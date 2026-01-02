#pragma once

typedef struct ConCommand
{
    char *name;
    unsigned long hash;
    bool (*func)(int argc, char *args[], char errstr[]);
} ConCommand;

void init_console();

void set_console_active(bool is_active);
bool get_console_active();

bool register_concommand(ConCommand concmd);

const char *console_input_str();
