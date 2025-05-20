#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILEPATH_RECORDED 4096
#define MAX_FILE_SIZE		  2048

//int main(void)
//{
//    InitAudioDevice();
//
//    const char* filename = "C:\\Users\\abhianu\\OneDrive\\Desktop\\helloworld\\assests\\Hallofmountainking.wav";
//
//    if (!FileExists(filename)) {
//        printf("ERROR: File not found at path: %s\n", filename);
//        return 1;
//    }
//
//    Sound sound = LoadSound(filename);
//
//    if (sound.frameCount == 0) {
//        printf("ERROR: Sound failed to load (0 frames).\n");
//        return 1;
//    }
//
//    printf("SUCCESS: Sound loaded and playing...\n");
//    PlaySound(sound);
//
//    while (IsSoundPlaying(sound)) {
//         Wait
//    }
//
//    UnloadSound(sound);
//    CloseAudioDevice();
//
//    return 0;
//}


int main(void) {

	const int w_height = 800;
	const int w_width = 450;

	InitWindow(w_height, w_width, "Noise Cancellation Program");

	int filepathCounter = 0;
	char* filepath[MAX_FILEPATH_RECORDED] = { 0 };

	for (int i = 0; i < MAX_FILEPATH_RECORDED;i++) {
		filepath[i] = (char*)RL_CALLOC(MAX_FILE_SIZE, 1);
	}
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		if (IsFileDropped()) {
			FilePathList droppedFile = LoadDroppedFiles();
			for (int i = 0, offset = filepathCounter; i < (int)droppedFile.count;i++) {
				if (filepathCounter < (MAX_FILEPATH_RECORDED - 1)) {
					TextCopy(filepath[offset + i], droppedFile.paths[i]);
					filepathCounter++;
				}
			}
		}
	}
}