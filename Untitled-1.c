#include <stdio.h>
#include <stdint.h>

// Include the Windows API for a native, safe delay function
#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep((ms) * 1000)
#endif

int main(void) {
    printf("Starting safe hardware simulation...\n\n");

    // Finite loop to prevent background process locking
    for (int i = 0; i < 5; i++) {
        printf("[LED] ON\n");
        fflush(stdout);   // Force Windows console to print immediately
        sleep_ms(500);    // Safe, non-blocking OS native delay

        printf("[LED] OFF\n");
        fflush(stdout);   // Force Windows console to print immediately
        sleep_ms(500);    // Safe, non-blocking OS native delay
    }

    printf("\nSimulation finished successfully without errors!\n");
    return 0;
}
