#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <coreinit/screen.h>
#include <vpad/input.h>

int color[4] = {0, 0xFF0000FF, 0x00FF00FF, 0x0000FFFF};
int index = 0;

void drawCopyright()
{
    OSScreenPutFontEx(SCREEN_TV, 0, 16, "FuckU WiiU - By VCoding");
    OSScreenPutFontEx(SCREEN_DRC, 0, 16, "FuckU WiiU - By VCoding");
    OSScreenPutFontEx(SCREEN_TV, 0, 17, "Press the home button to exit...");
    OSScreenPutFontEx(SCREEN_DRC, 0, 17, "Press the home button to exit...");
}

void drawScreen(char* text) 
{
    OSScreenClearBufferEx(SCREEN_TV, color[index]);
    OSScreenClearBufferEx(SCREEN_DRC, color[index]);
    OSScreenPutFontEx(SCREEN_TV, 0, 0, text);
    OSScreenPutFontEx(SCREEN_DRC, 0, 0, text);
    drawCopyright();
    OSScreenFlipBuffersEx(SCREEN_TV);
    OSScreenFlipBuffersEx(SCREEN_DRC);
}

int main(int argc, char** argv)
{
    WHBProcInit();
    WHBLogConsoleInit();

    char* txt = "Fuck You.";
    drawScreen(txt);

    VPADStatus buffer;
    while(1)
    {
        VPADRead(VPAD_CHAN_0, &buffer, 1, NULL);
        if (buffer.trigger & VPAD_BUTTON_A)
        {
            txt = "Fuck You.";
            drawScreen(txt);
        }
        if (buffer.trigger & VPAD_BUTTON_B)
        {
            txt = "Bitch.";
            drawScreen(txt);
        }
        if (buffer.trigger & VPAD_BUTTON_X)
        {
            txt = "Shut Up.";
            drawScreen(txt);
        }
        if (buffer.trigger & VPAD_BUTTON_PLUS) {
            if(index <  3)
            {
                index += 1;
            }
            else
            {
                index = 0;
            }
            drawScreen(txt);
        }
        if (buffer.trigger & VPAD_BUTTON_Y)
        {
            OSScreenClearBufferEx(SCREEN_TV, color[index]);
            OSScreenClearBufferEx(SCREEN_DRC, color[index]);
            drawCopyright();
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
