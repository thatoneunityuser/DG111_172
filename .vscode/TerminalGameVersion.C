#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

typedef enum {
    CompileError = 0,
    LogicError,
    Anomaly_Image,
    none
} ErrorEnum;

typedef struct {
    ErrorEnum error;
} ErrorTypes;

typedef struct {
    char Error1[1000];
    char Error2[1000];
    char Error3[1000];
} TextForCompileError;

typedef struct {
    char Error1[1000];
    char Error2[1000];
    char Error3[1000];
} TextForLogicError;

typedef struct {
    char Error1[1000];
    char Error2[1000];
    char Error3[1000];
} TextForAnomalyError;

typedef struct {
    char normaltext[1000];
    char normaltext2[1000];
    char normaltext3[1000];
} CorrectCode;

// Global text pools
TextForCompileError textCompile;
TextForLogicError textLogic;
TextForAnomalyError textAnomaly;
CorrectCode textNormal;

void initGameTexts() {
    // Compile Errors
    sprintf(textCompile.Error1, "int main() {\n    printf(\"Syntax Error XXX\")\n    return 0;\n}");
    sprintf(textCompile.Error2, "int main() {\n    int x = ;\n    return 0;\n}");
    sprintf(textCompile.Error3, "void test() {\n    return 100;\n}");

    // Logic Errors
    sprintf(textLogic.Error1, "int calculate() {\n    // Expected: 1 + 1 = 2\n    return 1 + 1 == -1;\n}");
    sprintf(textLogic.Error2, "int count = 0;\nfor (int i = 0; i < 10; i--) {\n    count++;\n}");
    sprintf(textLogic.Error3, "int isEven(int n) {\n    if (n %% 2 == 1) return 1;\n    return 0;\n}");

    // Anomaly Errors
    sprintf(textAnomaly.Error1, "void observe() {\n    printf(\" mom mom look at that airplane \");\n}");
    sprintf(textAnomaly.Error2, "void scream() {\n    printf(\"Zeeeeed AHHHHHH\");\n}");
    sprintf(textAnomaly.Error3, "void secret() {\n    char *msg = \"ฌฟัหดหทหหดหดหดหดหดหดหดหดหดหดหดหดหดหดหดหดหด\";\n    // Anomaly warning: unauthorized heartbeats detected\n}");

    // Correct Code
    sprintf(textNormal.normaltext, "int main() {\n    printf(\"Hello World!\\n\");\n    return 0;\n}");
    sprintf(textNormal.normaltext2, "int add(int a, int b) {\n    return a + b;\n}");
    sprintf(textNormal.normaltext3, "int max(int a, int b) {\n    return (a > b) ? a : b;\n}");
}

const char* getDisplayText(ErrorEnum errorKind) {
    int pick = rand() % 3;
    switch (errorKind) {
        case CompileError:
            if (pick == 0) return textCompile.Error1;
            if (pick == 1) return textCompile.Error2;
            return textCompile.Error3;
        case LogicError:
            if (pick == 0) return textLogic.Error1;
            if (pick == 1) return textLogic.Error2;
            return textLogic.Error3;
        case Anomaly_Image:
            if (pick == 0) return textAnomaly.Error1;
            if (pick == 1) return textAnomaly.Error2;
            return textAnomaly.Error3;
        case none:
        default:
            if (pick == 0) return textNormal.normaltext;
            if (pick == 1) return textNormal.normaltext2;
            return textNormal.normaltext3;
    }
}

ErrorTypes RandomErrorAndErrorText(int round) {
    ErrorTypes errorType;
    int randomChoice = rand() % 4;
    errorType.error = (ErrorEnum)randomChoice;

    printf("\n========================================\n");
    printf("               ROUND %d\n", round);
    printf("========================================\n");
    printf("--- Code Snippet ---\n%s\n", getDisplayText(errorType.error));
    printf("--------------------\n");

    return errorType;
}

int NextRound(int round) {
    return round + 1;
}

void checking(ErrorTypes errorType, char answer, int *correct_count, int *incorrect_count) {
    int hasError = (errorType.error != none);
    int playerThinksError = (answer == 'y' || answer == 'Y');

    if (playerThinksError == hasError) {
        printf("\n>>> Correct! <<<\n");
        (*correct_count)++;
    } else {
        printf("\n>>> Incorrect! <<<\n");
        if (hasError) {
            printf("[Info] There was an anomaly/error in this snippet!\n");
        } else {
            printf("[Info] This snippet was completely normal!\n");
        }
        (*incorrect_count)++;
    }
}

void GamePlaySection(int round, int *incorrect_count, int *correct_count) {
    ErrorTypes errorType = RandomErrorAndErrorText(round);

    printf("Is it error? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    checking(errorType, answer, correct_count, incorrect_count);

    printf("Round: %d | Correct: %d/10 | Incorrect: %d/3\n", round, *correct_count, *incorrect_count);
    printf("\nPress any key for the next round...\n");
    getch();
}

int main() {
    srand((unsigned int)time(NULL));
    initGameTexts();

    int round = 0;
    int incorrect_count = 0;
    int correct_count = 0;

    printf("========================================\n");
    printf("      Welcome To Anomaly Checker\n");
    printf("========================================\n");
    printf("Press 1 to start the game: ");
    int start = 0;
    if (scanf("%d", &start) != 1 || start != 1) {
        printf("Exiting game.\n");
        return 0;
    }

    while (correct_count < 10 && incorrect_count < 3) {
        round = NextRound(round);
        GamePlaySection(round, &incorrect_count, &correct_count);
    }

    printf("\n========================================\n");
    if (correct_count >= 10) {
        printf("         *** YOU WIN! ***\n");
    } else {
        printf("        *** GAME OVER! ***\n");
    }
    printf("Total Rounds: %d | Correct: %d | Incorrect: %d\n", round, correct_count, incorrect_count);
    printf("========================================\n");

    printf("\nPress any key to exit...\n");
    getch();
    return 0;
}
