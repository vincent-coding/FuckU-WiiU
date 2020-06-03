#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <coreinit/ios.h>
#include <coreinit/mcp.h>
#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/screen.h>
#include <vpad/input.h>

int main(int argc, char** argv)
{
    WHBProcInit();
    WHBLogConsoleInit();
    
    OSScreenClearBufferEx(SCREEN_TV, 0);
    OSScreenClearBufferEx(SCREEN_DRC, 0);
    
    OSScreenPutFontEx(SCREEN_TV, 0, 0, "Fuck you.");
    OSScreenPutFontEx(SCREEN_DRC, 0, 0, "Fuck you.");

    OSScreenFlipBuffersEx(SCREEN_TV);
    OSScreenFlipBuffersEx(SCREEN_DRC);

    VPADStatus buffer;
    while(1)
    {
        VPADRead(VPAD_CHAN_0, &buffer, 1, NULL);
        if (buffer.trigger & VPAD_BUTTON_A)
        {
            OSScreenClearBufferEx(SCREEN_TV, 0);
            OSScreenClearBufferEx(SCREEN_DRC, 0);
            OSScreenPutFontEx(SCREEN_TV, 0, 0, "Fuck you.");
            OSScreenPutFontEx(SCREEN_DRC, 0, 0, "Fuck you.");
            OSScreenFlipBuffersEx(SCREEN_TV);
            OSScreenFlipBuffersEx(SCREEN_DRC);
        }
        if (buffer.trigger & VPAD_BUTTON_B)
        {
            OSScreenClearBufferEx(SCREEN_TV, 0);
            OSScreenClearBufferEx(SCREEN_DRC, 0);
            OSScreenPutFontEx(SCREEN_TV, 0, 0, "Bitch.");
            OSScreenPutFontEx(SCREEN_DRC, 0, 0, "Bitch.");
            OSScreenFlipBuffersEx(SCREEN_TV);
            OSScreenFlipBuffersEx(SCREEN_DRC);
        }
        if (buffer.trigger & VPAD_BUTTON_X)
        {
            OSScreenClearBufferEx(SCREEN_TV, 0);
            OSScreenClearBufferEx(SCREEN_DRC, 0);
            OSScreenPutFontEx(SCREEN_TV, 0, 0, "Shut up.");
            OSScreenPutFontEx(SCREEN_DRC, 0, 0, "Shut up.");
            OSScreenFlipBuffersEx(SCREEN_TV);
            OSScreenFlipBuffersEx(SCREEN_DRC);
        }
        if (buffer.trigger & VPAD_BUTTON_Y)
        {
            OSScreenClearBufferEx(SCREEN_TV, 0);
            OSScreenClearBufferEx(SCREEN_DRC, 0);
            OSScreenFlipBuffersEx(SCREEN_TV);
            OSScreenFlipBuffersEx(SCREEN_DRC);
        }
        if (buffer.trigger & VPAD_BUTTON_HOME)
        {
            break;
        }
    }
    
    WHBLogConsoleFree();
    WHBProcShutdown();
    return 0;
}
