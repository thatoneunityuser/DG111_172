#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define FILENAME "errortxt"
typedef enum
{

    RunTimeError,
    CompileError,
    LogicError,
    HorrorError,
    FreakyError
} ErrorKind;
bool IsError(ErrorKind kind)
{
    switch (kind)
    {
    case RunTimeError:
        return true;
    case CompileError:
        return true;
    case LogicError:
        return true;
    case HorrorError:
        return true;
    case FreakyError:
        return true;
    default:
        return false;
    }
}

// this is possible error that you can detect while this game is playing

void RandomGenerateErrors(ErrorKind kind)
{
    switch (kind)
    {
    case RunTimeError:

        printf("RunTimeError detected!\n");
        break;
    case CompileError:
        printf("CompileError detected!\n");
        break;
    case LogicError:
        printf("LogicError detected!\n");
        break;
    case HorrorError:
        printf("HorrorError detected!\n");
        break;
    case FreakyError:
        printf("FreakyError detected!\n");
        break;
    default:
        printf("Hello World!\n");
        break;
    }
}
bool IsRansomIsHere(int chance)
{
    int random = rand() % 100;
    if (random < chance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int IncreasingRansomChance(int chance)
{
    if (chance < 100)
    {
        chance += 10;
    }
    return chance;
}
