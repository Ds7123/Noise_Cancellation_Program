#include "raylib.h"
#include <stdio.h>

int main(void)
{
    InitAudioDevice();

    const char* filename = "C:\\Users\\abhianu\\OneDrive\\Desktop\\helloworld\\assests\\Hallofmountainking.wav";

    if (!FileExists(filename)) {
        printf("ERROR: File not found at path: %s\n", filename);
        return 1;
    }

    Sound sound = LoadSound(filename);

    if (sound.frameCount == 0) {
        printf("ERROR: Sound failed to load (0 frames).\n");
        return 1;
    }

    printf("SUCCESS: Sound loaded and playing...\n");
    PlaySound(sound);

    while (IsSoundPlaying(sound)) {
        // Wait
    }

    UnloadSound(sound);
    CloseAudioDevice();

    return 0;
}
