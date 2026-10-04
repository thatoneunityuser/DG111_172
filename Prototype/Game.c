#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "Error List.txt"
#define MAX_ENTRIES 100
#define MAX_DIALOGUE 200
#define MAX_LINE 512
#define MAX_INCORRECT 2

typedef enum {
    NONE = 0,
    COMPILE_ERROR,
    RUNTIME_ERROR,
    LOGIC_ERROR,
    FATAL_ERROR,
    HORROR_ERROR,
    FREAKY_ERROR
} ErrorCode;

typedef struct {
    char dialogue[MAX_DIALOGUE];
    ErrorCode error;
} DialogueEntry;

static void trim(char *text)
{
    char *start = text;
    size_t length;
    while (*start == ' ' || *start == '\t' || *start == '\r' || *start == '\n') start++;
    if (start != text) memmove(text, start, strlen(start) + 1);
    length = strlen(text);
    while (length > 0 && (text[length - 1] == ' ' || text[length - 1] == '\t' ||
                          text[length - 1] == '\r' || text[length - 1] == '\n')) {
        text[--length] = '\0';
    }
}

static void remove_quotes(char *text)
{
    size_t length = strlen(text);
    if (length >= 2 && text[0] == '"' && text[length - 1] == '"') {
        memmove(text, text + 1, length - 2);
        text[length - 2] = '\0';
    }
}

static ErrorCode error_from_text(const char *text)
{
    if (strcmp(text, "None") == 0) return NONE;
    if (strcmp(text, "Compile Error") == 0) return COMPILE_ERROR;
    if (strcmp(text, "Runtime Error") == 0) return RUNTIME_ERROR;
    if (strcmp(text, "Logic Error") == 0) return LOGIC_ERROR;
    if (strcmp(text, "Fatal Error") == 0) return FATAL_ERROR;
    if (strcmp(text, "Horror Error") == 0 || strcmp(text, "Horror_Error") == 0) return HORROR_ERROR;
    if (strcmp(text, "Freaky Error") == 0 || strcmp(text, "Freaky_Error") == 0) return FREAKY_ERROR;
    return -1;
}

static const char *error_name(ErrorCode error)
{
    switch (error) {
        case NONE: return "None";
        case COMPILE_ERROR: return "Compile Error";
        case RUNTIME_ERROR: return "Runtime Error";
        case LOGIC_ERROR: return "Logic Error";
        case FATAL_ERROR: return "Fatal Error";
        case HORROR_ERROR: return "Horror Error";
        case FREAKY_ERROR: return "Freaky Error";
        default: return "Unknown Error";
    }
}

static int load_entries(const char *filename, DialogueEntry entries[], int capacity)
{
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE];
    int count = 0;

    if (file == NULL) {
        perror(filename);
        return -1;
    }

    while (count < capacity && fgets(line, sizeof(line), file) != NULL) {
        char *separator;
        char *error_text;
        ErrorCode error;

        trim(line);
        if (line[0] == '\0' || line[0] == '#') continue;
        separator = strrchr(line, ',');
        if (separator == NULL) {
            fprintf(stderr, "Skipping malformed line: %s\n", line);
            continue;
        }
        *separator = '\0';
        error_text = separator + 1;
        trim(line);
        trim(error_text);
        remove_quotes(line);
        remove_quotes(error_text);
        trim(line);
        trim(error_text);
        error = error_from_text(error_text);

        if (error < 0 || line[0] == '\0') {
            fprintf(stderr, "Skipping invalid line: %s, %s\n", line, error_text);
            continue;
        }
        strncpy(entries[count].dialogue, line, MAX_DIALOGUE - 1);
        entries[count].dialogue[MAX_DIALOGUE - 1] = '\0';
        entries[count].error = error;
        count++;
    }
    fclose(file);
    return count;
}

static int read_choice(void)
{
    char line[32];
    char *end;
    long value;
    if (fgets(line, sizeof(line), stdin) == NULL) return -1;
    value = strtol(line, &end, 10);
    if (end == line) return -1;
    return (int)value;
}

int main(void)
{
    DialogueEntry entries[MAX_ENTRIES];
    int count = load_entries(FILE_NAME, entries, MAX_ENTRIES);
    int incorrect = 0;
    int round;
    int used[MAX_ENTRIES] = {0};

    if (count < 0) {
        count = load_entries("Prototype/" FILE_NAME, entries, MAX_ENTRIES);
    }
    if (count <= 0) {
        fprintf(stderr, "No valid dialogue entries were loaded from %s.\n", FILE_NAME);
        return 1;
    }
    srand((unsigned)time(NULL));
    printf("Welcome to the Error Simulator\n");
    printf("Loaded %d dialogue entries from %s.\n", count, FILE_NAME);

    for (round = 0; round < count && incorrect < MAX_INCORRECT; round++) {
        int index;
        int answer;

        do {
            index = rand() % count;
        } while (used[index]);
        used[index] = 1;
        ErrorCode guessed_error = NONE;

        printf("\nRound %d\nDialogue: %s\n", round + 1, entries[index].dialogue);
        printf("Is there an anomaly? (1 = yes, 0 = no): ");
        answer = read_choice();
        if (answer == 1) {
            printf("Choose the error (1 Compile, 2 Runtime, 3 Logic, 4 Fatal, 5 Horror, 6 Freaky): ");
            switch (read_choice()) {
                case 1: guessed_error = COMPILE_ERROR; break;
                case 2: guessed_error = RUNTIME_ERROR; break;
                case 3: guessed_error = LOGIC_ERROR; break;
                case 4: guessed_error = FATAL_ERROR; break;
                case 5: guessed_error = HORROR_ERROR; break;
                case 6: guessed_error = FREAKY_ERROR; break;
                default: guessed_error = -1; break;
            }
        } else if (answer != 0) {
            printf("Invalid answer.\n");
            incorrect++;
            continue;
        }

        if ((answer == 0 && entries[index].error == NONE) ||
            (answer == 1 && guessed_error == entries[index].error)) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. Correct answer: %s\n", error_name(entries[index].error));
            incorrect++;
        }
    }
    if (incorrect >= MAX_INCORRECT) printf("You lose after %d incorrect answers.\n", incorrect);
    else printf("Game finished.\n");
    return 0;
}




