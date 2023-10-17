#include <iostream>
#include <string.h>
using namespace std;

class Android {
    public:
        virtual ~Android() = default;

        char *RunAndroidGame() const {
            char android_game[] = {0x31, 0x5e, 0x54, 0x62, 0x5f, 0x59, 0x54, 0x10, 0x37, 0x51, 0x5d, 0x55, 0};
            char *memory = new char[sizeof(android_game) + 1];
            *memory = sizeof(android_game);
            memcpy(memory+1, android_game, sizeof(android_game));
            return memory;
        }
};

class Windows {
    public:
        virtual std::string RunWindowsGame() const {
            char pc_game[] = "PC Game";
            int game_size = sizeof(pc_game);
            std::string game_content = "";
            for(int i = 0; i < game_size; i++){
                game_content += pc_game[i];
            }
            return game_content + " Running";
        }
};

class VirtualEmulator : public Windows {
    private:
        Android *mobile_;
    public:
        VirtualEmulator(Android *mobile) : mobile_(mobile) {}
        std::string RunWindowsGame() const {
            int virtual_machine = 0x10;
            std::string game_content = "";
            char *android_game = mobile_->RunAndroidGame();
            for(int i = 0; i < *android_game; i++){
                game_content += (char) (android_game[i+1] + virtual_machine);
            }
            delete android_game;
            return game_content + " Running";
        }
};

void client_code(Windows *windows){
    windows->RunWindowsGame();
}

int main() {
    Android *phone = new Android();
    Windows *pc = new Windows();
    VirtualEmulator *ve = new VirtualEmulator(phone);
    std::cout << pc->RunWindowsGame() << "\n";
    std::cout << phone->RunAndroidGame() << "\n";
    std::cout << ve->RunWindowsGame() << "\n";
    return 0;
}