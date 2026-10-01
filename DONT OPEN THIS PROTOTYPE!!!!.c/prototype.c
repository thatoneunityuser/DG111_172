#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define FILENAME "errortxt"
typedef enum
{
    none,
    RunTimeError,
    CompileError,
    LogicError,
    HorrorError,
    FreakyError
} ErrorKind;

typedef struct
{
    char Error[1999];
    ErrorKind ErrorType;
} Anomaly;

Anomaly currentAnomaly = {0};

static void TrimWhitespace(char *text)
{
    if (text == NULL)
        return;

    char *start = text;
    while (*start == ' ' || *start == '\t' || *start == '\r' || *start == '\n' || *start == '"')
        start++;

    if (start != text)
        memmove(text, start, strlen(start) + 1);

    size_t len = strlen(text);
    while (len > 0 && (text[len - 1] == ' ' || text[len - 1] == '\t' || text[len - 1] == '\r' || text[len - 1] == '\n' || text[len - 1] == '"'))
    {
        text[len - 1] = '\0';
        len--;
    }
}

static ErrorKind ParseErrorType(const char *rawType)
{
    if (rawType == NULL)
        return none;

    char normalized[64] = {0};
    size_t j = 0;

    for (size_t i = 0; rawType[i] != '\0' && j + 1 < sizeof(normalized); i++)
    {
        unsigned char ch = (unsigned char)rawType[i];
        if (isalnum(ch))
        {
            normalized[j++] = (char)tolower(ch);
        }
    }

    if (strcmp(normalized, "none") == 0)
        return none;
    if (strcmp(normalized, "runtimeerror") == 0)
        return RunTimeError;
    if (strcmp(normalized, "compileerror") == 0 || strcmp(normalized, "complieerror") == 0)
        return CompileError;
    if (strcmp(normalized, "logicerror") == 0)
        return LogicError;
    if (strcmp(normalized, "horrorerror") == 0)
        return HorrorError;
    if (strcmp(normalized, "freakyerror") == 0)
        return FreakyError;

    return none;
}

void PullDataFromTXT(Anomaly *a, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        strcpy(a->Error, "File not found.");
        a->ErrorType = RunTimeError;
        return;
    }

    char line[2048];
    if (fgets(line, sizeof(line), f) == NULL)
    {
        strcpy(a->Error, "Failed to read data from file.");
        a->ErrorType = LogicError;
        fclose(f);
        return;
    }

    fclose(f);

    char *firstComma = strchr(line, ',');
    char *lastComma = strrchr(line, ',');

    if (firstComma == NULL || lastComma == NULL || lastComma <= firstComma)
    {
        strcpy(a->Error, "Invalid data format in file.");
        a->ErrorType = LogicError;
        return;
    }

    *firstComma = '\0';
    *lastComma = '\0';

    char *label = line;
    char *message = firstComma + 1;
    char *type = lastComma + 1;

    TrimWhitespace(label);
    TrimWhitespace(message);
    TrimWhitespace(type);

    if (strcmp(label, "Anomaly") != 0)
    {
        strcpy(a->Error, "Unexpected data label.");
        a->ErrorType = LogicError;
        return;
    }

    snprintf(a->Error, sizeof(a->Error), "%s", message);
    a->ErrorType = ParseErrorType(type);
}

void StartGame()
{
    printf("Starting the game...\n");
}

void ChooseAnomaly(Anomaly *a)
{
    printf("Choose an anomaly:\n");
    printf("1. RunTimeError\n");
    printf("2. CompileError\n");
    printf("3. LogicError\n");
    printf("4. HorrorError\n");
    printf("5. FreakyError\n");

    int choice;
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (choice)
    {
    case 1:
        a->ErrorType = RunTimeError;
        break;
    case 2:
        a->ErrorType = CompileError;
        break;
    case 3:
        a->ErrorType = LogicError;
        break;
    case 4:
        a->ErrorType = HorrorError;
        break;
    case 5:
        a->ErrorType = FreakyError;
        break;
    default:
        printf("Invalid choice.\n");
        ChooseAnomaly(a);
        return;
    }
}

void ShowAnomaly(const Anomaly *a)
{
    printf("Current anomaly: %s\n", a->Error);
    switch (a->ErrorType)
    {
    case RunTimeError:

        break;
    case CompileError:

        break;
    case LogicError:

        break;
    case HorrorError:

        break;
    case FreakyError:

        break;
    default:

        break;
    }
}

void AnomalyCorrection(Anomaly *a)
{
    switch (a->ErrorType)
    {
    case RunTimeError:
        printf("Correcting RunTimeError...\n");
        break;
    case CompileError:
        printf("Correcting CompileError...\n");
        break;
    case LogicError:
        printf("Correcting LogicError...\n");
        break;
    case HorrorError:
        printf("Correcting HorrorError...\n");
        break;
    case FreakyError:
        printf("Correcting FreakyError...\n");
        break;
    default:
        printf("No anomaly to correct.\n");
        return;
    }
}

int InThegame(int *Round, int *Correct);

int NextRounds(int *Round, int *Correct)
{
    if (Round == NULL || Correct == NULL)
    {
        printf("Game state is missing.\n");
        return 0;
    }

    (*Round)++;
    printf("Round %d\n", *Round);

    if (*Round >= 5)
    {
        printf("Game Over! You have completed all rounds.\n");
        printf("Final score: %d\n", *Correct);
        return 0;
    }

    return InThegame(&*Round, &*Correct);
}

int InThegame(int *Round, int *Correct)
{
    if (Round == NULL || Correct == NULL)
    {
        printf("Invalid game state.\n");
        return 0;
    }

    ShowAnomaly(&currentAnomaly);

    printf("Is there an anomaly? (Y/N): ");
    char choice;
    if (scanf(" %c", &choice) != 1)
    {
        printf("Invalid input.\n");
        return 0;
    }

    if (choice == 'Y' || choice == 'y')
    {
        printf("Which anomaly do you think it is? (1-5, 1. RunTimeError, 2. CompileError, 3. LogicError, 4. HorrorError, 5. FreakyError): ");
        int anomalyChoice;
        if (scanf("%d", &anomalyChoice) != 1)
        {
            printf("Invalid input.\n");
            return 0;
        }

        int correct = 0;
        switch (anomalyChoice)
        {
        case 1:
            correct = (currentAnomaly.ErrorType == RunTimeError);
            break;
        case 2:
            correct = (currentAnomaly.ErrorType == CompileError);
            break;
        case 3:
            correct = (currentAnomaly.ErrorType == LogicError);
            break;
        case 4:
            correct = (currentAnomaly.ErrorType == HorrorError);
            break;
        case 5:
            correct = (currentAnomaly.ErrorType == FreakyError);
            break;
        default:
            printf("Invalid anomaly choice.\n");
            return 0;
        }

        if (correct)
        {
            printf("Correct! You have corrected the anomaly.\n");
            AnomalyCorrection(&currentAnomaly);
            (*Correct)++;
        }
        else
        {
            printf("Incorrect! The anomaly persists.\n");
        }

        return NextRounds(Round, Correct);
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Wrong! There is an anomaly. You must correct it.\n");
        AnomalyCorrection(&currentAnomaly);
        return NextRounds(Round, Correct);
    }
    else
    {
        printf("Invalid input. Please enter Y or N.\n");
        return InThegame(Round, Correct);
    }
}

int main()
{
    int Round = 0;
    int Correct = 0;

    printf("Pulling data from errortxt.txt...\n");
    PullDataFromTXT(&currentAnomaly, FILENAME);

    if (currentAnomaly.ErrorType == none)
    {
        strcpy(currentAnomaly.Error, "Logic failure detected.");
        currentAnomaly.ErrorType = LogicError;
    }

    printf("Welcome to Anomaly DETECTOR 3000!\n");
    printf("Press Y to Start TheGame or N to Exit: ");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
        StartGame();
        Round++;
        InThegame(&Round, &Correct);
    }
    else
    {
        printf("Exiting the program.\n");
        return 0;
    }

    printf("Final score: %d\n", Correct);
    return 0;
}
