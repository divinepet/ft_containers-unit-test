#include "lib.hpp"
#include "bass24/banner.hpp"
#include "engine.ipp"

void showAchievment(std::string filename, int output_udelay, void (banner)(int), int snd_delay) {
    if (!BASS_Init(-1, 44100, 0, NULL ,NULL))
    {
        //            cout<<"Can't initialize device";
        return ;
    }

    int stream = BASS_StreamCreateFile(false, filename.c_str(), 0L, 0L, 0);
    if (stream != 0)
    {
	BASS_ChannelSetAttribute(stream, BASS_ATTRIB_VOL, 0.05);
        // play the stream channel
        BASS_ChannelPlay(stream, false);
    }
    else
    {
        // error creating the stream
        cout<<"Stream error: {0}", BASS_ErrorGetCode();
    }
	banner(output_udelay);
    usleep(snd_delay);


    BASS_StreamFree(stream);
    // free BASS
    BASS_Free();
}

int main() {

    int num_passed = 0;
    int num_passed_bonus = 0;
    bool is_bonus = 0;

    const char* filename[4] = {
            "./results/vector_res",
            "./results/utilities_res",
            "./results/stack_res",
            "./results/map_res"
    };
    const char* filename_bonus[1] = {
            "./results/set_res"
    };

    std::string buf;
    std::fstream fin;

    for (int i = 0; i < _TASK_NUM; ++i) {
        fin.open(filename[i]);
        if (fin.is_open()) {
            std::getline(fin, buf);
            num_passed += stoi(buf);
            fin.close();
        }
        else {
            std::cout << WHITE + "ERROR: Results not found" + RESET << std::endl;
            return (1);
        }
    }
    for (int i = 0; i < _TASK_NUM_BONUS; ++i) {
        fin.open(filename_bonus[i]);
        if (fin.is_open()) {
            std::getline(fin, buf);
            num_passed_bonus += stoi(buf);
            fin.close();
            is_bonus = true;
        }
        else {
            is_bonus = false;
        }
    }
    
    if (!is_bonus) {
        outputTotalResult(num_passed, _TOTAL_TEST_NUM);
        if (num_passed == _TOTAL_TEST_NUM) {
        	showAchievment("./bass24/mp3/Vice_Complete.mp3", 300000, outputBanner, 3770000);
        }
    }
    else {
        outputTotalResult(num_passed + num_passed_bonus, _TOTAL_TEST_NUM_BONUS);
        if (num_passed + num_passed_bonus == _TOTAL_TEST_NUM_BONUS) {
        	showAchievment("./bass24/mp3/SA_Complete.mp3", 200000, outputBannerBonus, 7300000);
        }
    }

    return (0);
}
