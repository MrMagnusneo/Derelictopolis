#include "console.h"
#include "util.h"
#include <string.h>

#define CONINPUT_MAX 128

static ConCommand all_concmds[];
static char console_inp[CONINPUT_MAX];

bool createchunk_func(int argc, char *args[], char errstr[])
{

}

void init_console()
{
    // TODO
    ConCommand createchunk_cmd;
    char *createchunk_name = mallocstr("createchunk");
    createchunk_cmd.name = createchunk_name;
    createchunk_cmd.func = &createchunk_func;
    // incomplete
    //register_concommand(createchunk_cmd);
}

const char *console_input_str()
{
    return console_inp;
}