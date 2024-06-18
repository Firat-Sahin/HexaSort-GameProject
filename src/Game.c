#include <raylib.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <ctime>

typedef enum {HADES, POSEDION, DEMETER, ZEUS, KRONOS, BOSS, SHOP, LEVELS, GAMEPLAY}Screen;

typedef struct{
    float length;
    Vector2 loc;
    Color color;
    bool statue;
    bool floor;
    bool hold;
    bool isclose;
    int Highers[24];
} floorBlock;

typedef struct{
    char name[9];
    int coin;
    int framecounter;
    int lettercount;
    int picture;
    int voice;
    int Stars[26];
    int FeatureCount[5];
    bool Locks[26];
    bool IsSoundOff;
    bool mouseOnText;
    Rectangle textBox;
} SavedData;

typedef struct{
    float height;
    float width;
    float current_time;
    float time_goal;
    int score;
    int score_goal;
    int moveCount;
    int move_goal;
    int selected;
    int size;
    int level;
    bool SettingsHold;
    bool BagHold;
    bool ProfilHold;
    bool exit;
    Screen PerviousScreen;
    Screen CurrentScreen;
    floorBlock Blocks[33];
    floorBlock ChosenBlock[3];
    SavedData Datas;
} GameState;

typedef struct{
    bool a1;
    bool a2;
    bool a3;
    bool a4;
} Condition;

typedef struct{
    Texture2D arrowB;
    Texture2D arrowd_L;
    Texture2D arrowd_R;
    Texture2D arrowh_R;
    Texture2D arrowk_L;
    Texture2D arrowk_R;
    Texture2D ArrowL;
    Texture2D arrowp_L;
    Texture2D arrowp_R;
    Texture2D arrowS;
    Texture2D arrowz_L;
    Texture2D arrowz_R;
    Texture2D background;
    Texture2D bag;
    Texture2D bronze;
    Texture2D bronzeG;
    Texture2D close;
    Texture2D coin;
    Texture2D coincounterB;
    Texture2D coinG;
    Texture2D counterD;
    Texture2D counterH;
    Texture2D counterK;
    Texture2D counterP;
    Texture2D counterZ;
    Texture2D cup;
    Texture2D deleteA;
    Texture2D demeter0;
    Texture2D demeter1;
    Texture2D demeter2;
    Texture2D demeter3;
    Texture2D demeter4;
    Texture2D demeter5;
    Texture2D diamond;
    Texture2D diamondG;
    Texture2D downD;
    Texture2D downH;
    Texture2D downK;
    Texture2D downP;
    Texture2D downZ;
    Texture2D featureD;
    Texture2D featureH;
    Texture2D featureK;
    Texture2D featureP;
    Texture2D featureZ;
    Texture2D frameB;
    Texture2D frameD;
    Texture2D frameH;
    Texture2D frameK;
    Texture2D frameP;
    Texture2D frameZ;
    Texture2D go;
    Texture2D gold;
    Texture2D goldG;
    Texture2D groundB;
    Texture2D groundD;
    Texture2D groundG;
    Texture2D groundG2;
    Texture2D groundH;
    Texture2D groundK;
    Texture2D groundL;
    Texture2D groundP;
    Texture2D groundS;
    Texture2D groundZ;
    Texture2D hades0;
    Texture2D hades1;
    Texture2D hades2;
    Texture2D hades3;
    Texture2D hades4;
    Texture2D hades5;
    Texture2D heart;
    Texture2D homeD;
    Texture2D homeH;
    Texture2D homeK;
    Texture2D homeP;
    Texture2D homeZ;
    Texture2D kronos0;
    Texture2D kronos1;
    Texture2D kronos2;
    Texture2D kronos3;
    Texture2D kronos4;
    Texture2D kronos5;
    Texture2D L1;
    Texture2D L2;
    Texture2D L3;
    Texture2D L4;
    Texture2D L5;
    Texture2D L6;
    Texture2D L7;
    Texture2D L8;
    Texture2D L9;
    Texture2D L10;
    Texture2D L11;
    Texture2D L12;
    Texture2D L13;
    Texture2D L14;
    Texture2D L15;
    Texture2D L16;
    Texture2D L17;
    Texture2D L18;
    Texture2D L19;
    Texture2D L20;
    Texture2D L21;
    Texture2D L22;
    Texture2D L23;
    Texture2D L24;
    Texture2D L25;
    Texture2D L26;
    Texture2D lockedD;
    Texture2D lockedH;
    Texture2D lockedK;
    Texture2D lockedP;
    Texture2D lockedZ;
    Texture2D move;
    Texture2D move2;
    Texture2D playB;
    Texture2D poseidon0;
    Texture2D poseidon1;
    Texture2D poseidon2;
    Texture2D poseidon3;
    Texture2D poseidon4;
    Texture2D poseidon5;
    Texture2D profileB;
    Texture2D ProfileB2;
    Texture2D profileD;
    Texture2D profileD2;
    Texture2D profileH;
    Texture2D profileH2;
    Texture2D profileK;
    Texture2D profileK2;
    Texture2D profileP;
    Texture2D profileP2;
    Texture2D profileZ;
    Texture2D profileZ2;
    Texture2D settingsB;
    Texture2D settingsD;
    Texture2D settingsG;
    Texture2D settingsH;
    Texture2D settingsK;
    Texture2D settingsP;
    Texture2D settingsS;
    Texture2D settingsZ;
    Texture2D shopD;
    Texture2D shopH;
    Texture2D shopK;
    Texture2D shopP;
    Texture2D shopZ;
    Texture2D soundOff;
    Texture2D starD;
    Texture2D starH;
    Texture2D starK;
    Texture2D starP;
    Texture2D starZ;
    Texture2D textD;
    Texture2D textH;
    Texture2D textK;
    Texture2D textP;
    Texture2D textZ;
    Texture2D timer;
    Texture2D timer2;
    Texture2D zeus0;
    Texture2D zeus1;
    Texture2D zeus2;
    Texture2D zeus3;
    Texture2D zeus4;
    Texture2D zeus5;
} AllImages;

Color DARKBLUE_2 = {8, 58, 112, 255};
Color YELLOW_2 = {196, 194, 43, 255};
Color RED_2 = {176, 32, 42, 255};
Color GREEN_2 = {43, 186, 73, 255};
Color VIOLET_2 = {95, 15, 153, 255};
Color ORANGE_2 = {209, 137, 13, 255};
Color PINK_2 = {204, 78, 151, 255};
Color SKYBLUE_2 = {78, 151, 204, 255};
Color MAGENTA_2 = {196, 33, 196, 255};
Color DARKGRAY_2 = {45, 45, 45, 255};

void LoadSave(SavedData*);
void UnloadSave(SavedData*);
void DrawBackgroundG(AllImages, GameState*, Sound);
void DrawBackgroundH(AllImages, GameState*, Sound);
void DrawBackgroundP(AllImages, GameState*, Sound);
void DrawBackgroundD(AllImages, GameState*, Sound);
void DrawBackgroundZ(AllImages, GameState*, Sound);
void DrawBackgroundK(AllImages, GameState*, Sound);
void DrawBackgroundB(AllImages, GameState*, Sound);
void DrawBackgroundL(AllImages, GameState*, Sound);
void DrawBackgroundS(AllImages, GameState*, Sound);
void SetBlock(floorBlock*, float, float);
void SetEmptyData(SavedData*);
void SetGameState(GameState*, int);
void MakeHexagon(floorBlock);
void MakeHexagonMore(floorBlock[], int);
void MakeFloorBlockList(floorBlock[], int, floorBlock);
void MakeRandomBlock(floorBlock[], int);
void RandomColor(int[], int);
void TurnWhite(floorBlock[], int);
void TurnStatue(floorBlock*, int, int);
void ColorChange(Color*);
void HoldHexa(GameState*, Sound, Sound);
void OrganiseBlocks(floorBlock[], int, int, int*);
void ChangeBlocks(int*, int*, int*);
void CloseBlock(floorBlock*, int, int*); // DeleteBlock fonksiyonundan farkli olarak bloklari gecici bir sureligine kapatiyor.
void mixList(floorBlock[], int);
void InitName(SavedData*);
void UseFeature(GameState*);
bool IsPlaceable(floorBlock);
bool IsEmpty(floorBlock[]);
bool IsOver(floorBlock[], int);
int IsFinished(GameState, int);
int DeleteBlock(floorBlock[], int, int); // dizideki isteğimiz elemani kapatiyor
int AddBlock(floorBlock[], int, int, int); // Platforma ve diziye yeni bloklar ekliyor
int WhichFloorIsMouseOn(floorBlock[], int);
int TheLastColor(floorBlock);
int GiveMeIndex(floorBlock[], int, float, float);
int EndScreen(GameState*, int, AllImages, bool, Sound);
int GamePlay(GameState*, AllImages, Sound, Sound, Sound);
int Level(AllImages, GameState*, Sound, Sound, Sound);
int IsMouseOnImagesG(GameState*, AllImages , Sound);
int IsMouseOnSettingsG(GameState*, AllImages , Sound);
int IsMouseOnBagG(GameState*, AllImages , Sound);
int IsMouseOnImagesH(GameState*, AllImages , Sound);
int IsMouseOnImagesP(GameState*, AllImages , Sound);
int IsMouseOnImagesD(GameState*, AllImages , Sound);
int IsMouseOnImagesZ(GameState*, AllImages , Sound);
int IsMouseOnImagesK(GameState*, AllImages , Sound);
int IsMouseOnImagesB(GameState*, AllImages , Sound);
int IsMouseOnImagesL(GameState*, AllImages , Sound);
int IsMouseOnImagesS(GameState*, AllImages , Sound);
int IsMouseOnSettings(GameState*, AllImages , Sound);
int IsMouseOnProfil(GameState*, AllImages , Sound);
int LoadAllImages(AllImages*);
int UnloadAllImages(AllImages*);

int main(void) {

    InitWindow(1366, 768, "Hexa Sort 2");
    SetTargetFPS(60);
    srand(time(NULL));
    InitAudioDevice();
    AllImages Images;

    LoadAllImages(&Images);
    
    Sound mymusicB = LoadSound("C:\\HexaSort2\\resources\\mymusicB.mp3");
    Sound mymusicD = LoadSound("C:\\HexaSort2\\resources\\mymusicD.mp3");
    Sound mymusicH = LoadSound("C:\\HexaSort2\\resources\\mymusicH.mp3");
    Sound mymusicK = LoadSound("C:\\HexaSort2\\resources\\mymusicK.mp3");
    Sound mymusicP = LoadSound("C:\\HexaSort2\\resources\\mymusicP.mp3");
    Sound mymusicZ = LoadSound("C:\\HexaSort2\\resources\\mymusicZ.mp3");
    Sound clickS = LoadSound("C:\\HexaSort2\\resources\\clickS.mp3");
    Sound pick = LoadSound("C:\\HexaSort2\\resources\\pick.mp3");
    Sound put = LoadSound("C:\\HexaSort2\\resources\\put.mp3");

    GameState States;
    SetGameState(&States, 1);
    LoadSave(&(States.Datas));

    while(!(States.exit)) {
        BeginDrawing();
        
        switch(States.CurrentScreen) {
            case HADES:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicH); States.Datas.voice = 0;}
                DrawBackgroundH(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicH);}
                break;
            case POSEDION:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicP); States.Datas.voice = 0;}
                DrawBackgroundP(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicP);}
                break;
            case DEMETER:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicD); States.Datas.voice = 0;}
                DrawBackgroundD(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicD);}
                break;
            case ZEUS:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicZ); States.Datas.voice = 0;}
                DrawBackgroundZ(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicZ);}
                break;
            case KRONOS:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicK); States.Datas.voice = 0;}
                DrawBackgroundK(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicK);}
                break;
            case BOSS:
                if(States.Datas.voice == 1 && !(States.Datas.IsSoundOff)) {PlaySound(mymusicB); States.Datas.voice = 0;}
                DrawBackgroundB(Images, &States, clickS);
                if(States.Datas.voice == 1 || States.Datas.IsSoundOff) {StopSound(mymusicB);}
                break;
            case SHOP:
                DrawBackgroundS(Images, &States, clickS);
                break;
            case LEVELS:
                DrawBackgroundL(Images, &States, clickS);
                break;
            case GAMEPLAY:
                Level(Images, &States, clickS, pick, put);
                break;
        }

        EndDrawing();
    }

    UnloadSave(&(States.Datas));

    UnloadAllImages(&Images);
    
    UnloadSound(mymusicB);
    UnloadSound(mymusicD);
    UnloadSound(mymusicH);
    UnloadSound(mymusicK);
    UnloadSound(mymusicP);
    UnloadSound(mymusicZ);
    UnloadSound(clickS);
    UnloadSound(pick);
    UnloadSound(put);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

void LoadSave(SavedData *Datas) {
    FILE *fPtr = NULL;

    if((fPtr = fopen("C:\\HexaSort2\\Save.dat", "rb+")) == NULL) {
        fPtr = fopen("C:\\HexaSort2\\Save.dat", "wb");
        SetEmptyData(Datas);
        fwrite(Datas, sizeof(SavedData), 1, fPtr);
        fclose(fPtr);
    } else {
        fread(Datas, sizeof(SavedData), 1, fPtr);
        fclose(fPtr);
    }
}

void UnloadSave(SavedData *Datas) {
    Datas -> voice = 1;
    FILE *fPtr = NULL;
    fPtr = fopen("C:\\HexaSort2\\Save.dat", "rb+");
    fseek(fPtr, 0*sizeof(SavedData), SEEK_SET);
    fwrite(Datas, sizeof(SavedData), 1, fPtr);
}

void DrawBackgroundG(AllImages Images, GameState* States, Sound clickS) {
    States->current_time += 0.016667;
    int ratio = 180*(States->score)/(States->score_goal);
    if(ratio>180) {ratio=180;}
    
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundG, GetScreenWidth() / 2 - 215, 0, WHITE);
    DrawTexture(Images.timer, GetScreenWidth()/2 - 205, + 35, WHITE);
    DrawTexture(Images.move, GetScreenWidth()/2 - 195, 0, WHITE);

    DrawText(TextFormat("%.2d:%.2d:%.2d", (int) States->current_time/60, (int) States->current_time%60, (int) (States->current_time*100)%60), 496, 85, 20, BLACK);
    DrawRectangle(605, 25, ratio, 30, YELLOW);
    DrawRectangleLinesEx((Rectangle) { 605, 25, 180, 30 }, 2.0, DARKBLUE);
    DrawText(TextFormat("%d/%d", States->score, States->score_goal), 665, 32, 20, WHITE);
    DrawText(TextFormat("%d", States->moveCount), 560, 30, 20, BLACK);

    if(States -> SettingsHold == true){
        DrawRectangleRec((Rectangle){798, 0, 100, 200}, DARKGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 146 , + 20, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 146 , + 80, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 146 , + 143, WHITE);
        IsMouseOnSettingsG(States, Images, clickS);
    }

    if(States -> BagHold == true){
        DrawRectangleRec((Rectangle){722, 66, 176, 60}, WHITE);
        if(States -> Datas.FeatureCount[0] != 0) {DrawTexture(Images.featureH, GetScreenWidth()/2 + 11, + 40, WHITE);}
        if(States -> Datas.FeatureCount[2] != 0) {DrawTexture(Images.featureP, GetScreenWidth()/2 + 55 , + 40, WHITE);}
        if(States -> Datas.FeatureCount[3] != 0) {DrawTexture(Images.featureZ, GetScreenWidth()/2 + 101 , + 40, WHITE);}
        if(States -> Datas.FeatureCount[4] != 0) {DrawTexture(Images.featureK, GetScreenWidth()/2 + 143, + 40, WHITE);}
        if(States -> Datas.FeatureCount[0] == 0) {DrawTexture(Images.featureH, GetScreenWidth()/2 + 11, + 40, BLACK);}
        if(States -> Datas.FeatureCount[2] == 0) {DrawTexture(Images.featureP, GetScreenWidth()/2 + 55 , + 40, BLACK);}
        if(States -> Datas.FeatureCount[3] == 0) {DrawTexture(Images.featureZ, GetScreenWidth()/2 + 101 , + 40, BLACK);}
        if(States -> Datas.FeatureCount[4] == 0) {DrawTexture(Images.featureK, GetScreenWidth()/2 + 143, + 40, BLACK);}
        DrawText(TextFormat("%2d", States -> Datas.FeatureCount[0]), 737, 110, 15, BLACK);
        DrawText(TextFormat("%2d", States -> Datas.FeatureCount[2]), 783, 110, 15,BLACK);
        DrawText(TextFormat("%2d", States -> Datas.FeatureCount[3]), 825, 110, 15, BLACK);
        DrawText(TextFormat("%2d", States -> Datas.FeatureCount[4]), 870, 110, 15, BLACK);
        
        IsMouseOnBagG(States, Images, clickS);

        if(States -> selected > 0) {
            DrawRectangleLinesEx((Rectangle) { (float) 678 + 44*(States -> selected), 66, 44, 60 }, 2.0, GOLD);
        }
    }

    UseFeature(States);
    IsMouseOnImagesG(States, Images, clickS);
}

void DrawBackgroundH(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundH, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.heart, GetScreenWidth()/2 - 40, +10, WHITE);
    DrawTexture(Images.settingsH, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.counterH, GetScreenWidth()/2 - 15, +70, WHITE);
    DrawTexture(Images.downH, GetScreenWidth()/2 - 185, 550, WHITE);
    DrawTexture(Images.shopH, GetScreenWidth()/2 - 196, 592, WHITE);
    DrawTexture(Images.homeH, GetScreenWidth()/2 - 60, 590, WHITE);
    DrawTexture(Images.lockedH, GetScreenWidth()/2 + 65, 580, WHITE);
    DrawTexture(Images.arrowh_R, GetScreenWidth()/2 + 70 , + 240, WHITE);
    DrawTexture(Images.textH, GetScreenWidth()/2 - 100, + 360, WHITE);
    
    switch(IsFinished(*States, 0)) {
        case 0:
            DrawTexture(Images.hades0, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 1:
            DrawTexture(Images.hades1, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 2:
            DrawTexture(Images.hades2, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 3:
            DrawTexture(Images.hades3, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 4:
            DrawTexture(Images.hades4, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 5:
            DrawTexture(Images.hades5, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
    }
    
    DrawRectangleRec(States->Datas.textBox, LIGHTGRAY);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height,GOLD);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, RED);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, RED);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, RED);
    } 
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 688, 85, 20, RED);
    DrawText("SHOP", 524, 680, 17, GOLD);
    DrawText("HOME", 662, 680, 17,GOLD);
    DrawText("LEVELS", 790, 680, 17, GOLD);

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesH(States, Images, clickS);
}

void DrawBackgroundP(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundP, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.heart, GetScreenWidth()/2 - 40, +10, WHITE);
    DrawTexture(Images.settingsP, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.counterP, GetScreenWidth()/2 - 30, +60, WHITE);
    DrawTexture(Images.downP, GetScreenWidth()/2 - 185, 550, WHITE);
    DrawTexture(Images.shopP, GetScreenWidth()/2 - 196, 592, WHITE);
    DrawTexture(Images.homeP, GetScreenWidth()/2 - 60, 590, WHITE);
    DrawTexture(Images.lockedP, GetScreenWidth()/2 + 65, 580, WHITE);
    DrawTexture(Images.arrowp_L, GetScreenWidth()/2  - 230 , + 240, WHITE);
    DrawTexture(Images.arrowp_R, GetScreenWidth()/2 + 70 , + 240, WHITE);
    DrawTexture(Images.textP, GetScreenWidth()/2 - 100, + 390, WHITE);

    switch(IsFinished(*States, 1)) {
        case 0:
            DrawTexture(Images.poseidon0, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 1:
            DrawTexture(Images.poseidon1, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 2:
            DrawTexture(Images.poseidon2, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 3:
            DrawTexture(Images.poseidon3, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 4:
            DrawTexture(Images.poseidon4, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 5:
            DrawTexture(Images.poseidon5, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
    }
        
    DrawRectangleRec(States->Datas.textBox, LIGHTGRAY);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height,WHITE);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, BLUE);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, BLUE);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, BLUE);
    } 
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 688, 85, 20, BLUE);
    DrawText("SHOP", 524, 680, 17, DARKBLUE);
    DrawText("HOME", 662, 680, 17,DARKBLUE);
    DrawText("LEVELS", 790, 680, 17, DARKBLUE);

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesP(States, Images, clickS);
}

void DrawBackgroundD(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundD, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.heart, GetScreenWidth()/2 - 40, +10, WHITE);
    DrawTexture(Images.settingsD, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.counterD, GetScreenWidth()/2 - 15, +70, WHITE);
    DrawTexture(Images.downD, GetScreenWidth()/2 - 185, 550, WHITE);
    DrawTexture(Images.shopD, GetScreenWidth()/2 - 196, 592, WHITE);
    DrawTexture(Images.homeD, GetScreenWidth()/2 - 60, 590, WHITE);
    DrawTexture(Images.lockedD, GetScreenWidth()/2 + 65, 580, WHITE);
    DrawTexture(Images.arrowd_L, GetScreenWidth()/2  - 230 , + 240, WHITE);
    DrawTexture(Images.arrowd_R, GetScreenWidth()/2 + 70 , + 240, WHITE);
    DrawTexture(Images.textD, GetScreenWidth()/2 - 100, + 360, WHITE);

    switch(IsFinished(*States, 2)) {
        case 0:
            DrawTexture(Images.demeter0, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 1:
            DrawTexture(Images.demeter1, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 2:
            DrawTexture(Images.demeter2, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 3:
            DrawTexture(Images.demeter3, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 4:
            DrawTexture(Images.demeter4, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 5:
            DrawTexture(Images.demeter5, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
    }
        
    DrawRectangleRec(States->Datas.textBox, DARKGREEN);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, GREEN);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, GOLD);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, GOLD);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, YELLOW);
    } 
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 688, 85, 20, DARKGREEN);
    DrawText("SHOP", 524, 680, 17, GOLD);
    DrawText("HOME", 662, 680, 17,GOLD);
    DrawText("LEVELS", 790, 680, 17, GOLD);

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesD(States, Images, clickS);
}

void DrawBackgroundZ(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundZ, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.heart, GetScreenWidth()/2 - 40, +10, WHITE);
    DrawTexture(Images.settingsB, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.counterZ, GetScreenWidth()/2 - 15, +70, WHITE);
    DrawTexture(Images.downZ, GetScreenWidth()/2 - 185, 550, WHITE);
    DrawTexture(Images.shopZ, GetScreenWidth()/2 - 196, 592, WHITE);
    DrawTexture(Images.homeZ, GetScreenWidth()/2 - 60, 590, WHITE);
    DrawTexture(Images.lockedZ, GetScreenWidth()/2 + 65, 580, WHITE);
    DrawTexture(Images.arrowz_L, GetScreenWidth()/2  - 230 , + 240, WHITE);
    DrawTexture(Images.arrowz_R, GetScreenWidth()/2 + 70 , + 240, WHITE);
    DrawTexture(Images.textZ, GetScreenWidth()/2 - 100, + 360, WHITE);

    switch(IsFinished(*States, 3)) {
        case 0:
            DrawTexture(Images.zeus0, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 1:
            DrawTexture(Images.zeus1, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 2:
            DrawTexture(Images.zeus2, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 3:
            DrawTexture(Images.zeus3, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 4:
            DrawTexture(Images.zeus4, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
        case 5:
            DrawTexture(Images.zeus5, GetScreenWidth()/2 - 150 , + 160, WHITE);
            break;
    }
        
    DrawRectangleRec(States->Datas.textBox, LIGHTGRAY);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height,YELLOW);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, WHITE);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, YELLOW);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, YELLOW);
    } 
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 688, 85, 20, GOLD);
    DrawText("SHOP", 524, 680, 17, GOLD);
    DrawText("HOME", 662, 680, 17,GOLD);
    DrawText("LEVELS", 790, 680, 17, GOLD);

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesZ(States, Images, clickS);
}

void DrawBackgroundK(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundK, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.heart, GetScreenWidth()/2 - 40, +10, WHITE);
    DrawTexture(Images.settingsK, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.counterK, GetScreenWidth()/2 - 15, +70, WHITE);
    DrawTexture(Images.downK, GetScreenWidth()/2 - 185, 550, WHITE);
    DrawTexture(Images.shopK, GetScreenWidth()/2 - 196, 592, WHITE);
    DrawTexture(Images.homeK, GetScreenWidth()/2 - 60, 590, WHITE);
    DrawTexture(Images.lockedK, GetScreenWidth()/2 + 65, 580, WHITE);
    DrawTexture(Images.arrowk_L, GetScreenWidth()/2  - 230 , + 240, WHITE);
    DrawTexture(Images.arrowk_R, GetScreenWidth()/2 + 70 , + 240, WHITE);
    DrawTexture(Images.textK, GetScreenWidth()/2 - 100, + 360, WHITE);

    switch(IsFinished(*States, 4)) {
        case 0:
            DrawTexture(Images.kronos0, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
        case 1:
            DrawTexture(Images.kronos1, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
        case 2:
            DrawTexture(Images.kronos2, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
        case 3:
            DrawTexture(Images.kronos3, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
        case 4:
            DrawTexture(Images.kronos4, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
        case 5:
            DrawTexture(Images.kronos5, GetScreenWidth()/2 - 200 , 110, WHITE);
            break;
    }
        
    DrawRectangleRec(States->Datas.textBox, LIGHTGRAY);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height,WHITE);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, BLACK);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, BLACK);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, BLACK);
    } 
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 688, 85, 20, BLACK);
    DrawText("SHOP", 524, 680, 17, WHITE);
    DrawText("HOME", 662, 680, 17,WHITE);
    DrawText("LEVELS", 790, 680, 17, WHITE);

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesK(States, Images, clickS);
}

void DrawBackgroundB(AllImages Images, GameState* States, Sound clickS) {
    InitName(&(States->Datas));
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundB, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
    DrawTexture(Images.settingsB, GetScreenWidth()/2 + 95, 0, WHITE);
    DrawTexture(Images.playB, GetScreenWidth()/2 - 100, - 20, WHITE);
    DrawTexture(Images.arrowB, GetScreenWidth()/2  - 230 , + 240, WHITE);

    DrawRectangleRec(States->Datas.textBox, LIGHTGRAY);

    if (States->Datas.mouseOnText) DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height,WHITE);
    else DrawRectangleLines((int) States->Datas.textBox.x, (int) States->Datas.textBox.y, (int) States->Datas.textBox.width, (int) States->Datas.textBox.height, BLUE);

    DrawText(States->Datas.name, (int) States->Datas.textBox.x + 10, (int) States->Datas.textBox.y +5 , 10, BLUE);

    if ( States->Datas.mouseOnText && (States->Datas.lettercount < 8) && ((States->Datas.framecounter/20)%2) == 0 ){
        DrawText("_", (int) States->Datas.textBox.x + 10 + MeasureText(States->Datas.name, 4), (int) States->Datas.textBox.y + 5, 10, BLUE);
    }

    if(!(States -> ProfilHold)) {
        switch(States -> Datas.picture) {
            case 1:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileH2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 2:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileP2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 3:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileD2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 4:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileZ2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 5:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.profileK2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
            case 6:
                DrawTexture(Images.frameB, GetScreenWidth()/2 - 180, +5, WHITE);
                DrawTexture(Images.ProfileB2, GetScreenWidth()/2 - 146 , + 35, WHITE);
                break;
        }
    } else {
        DrawRectangleRec((Rectangle){498, 0, 180, 232}, WHITE);
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, WHITE);
        if(IsFinished(*States, 0) == 5) DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, WHITE);
        else DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, BLACK);
        if(IsFinished(*States, 1) == 5) DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, WHITE);
        else DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, BLACK);
        if(IsFinished(*States, 2) == 5) DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, WHITE);
        else DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, BLACK);
        if(IsFinished(*States, 3) == 5) DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, WHITE);
        else DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, BLACK);
        if(IsFinished(*States, 4) == 5) DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, WHITE);
        else DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, BLACK);
        IsMouseOnProfil(States, Images, clickS);
    }

    if(States -> SettingsHold) {
        DrawRectangleRec((Rectangle){768, 0, 100, 200}, LIGHTGRAY);
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, WHITE);
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, WHITE);
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, WHITE);
        IsMouseOnSettings(States, Images, clickS);
    }

    IsMouseOnImagesB(States, Images, clickS);
}

void DrawBackgroundL(AllImages Images, GameState* States, Sound clickS) {
    
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundL, GetScreenWidth()/2 - 370, 0, WHITE);
    DrawTexture(Images.ArrowL , GetScreenWidth()/2 - 480, + 10, WHITE);
    Texture2D AllLevels[26];
    AllLevels[0] = Images.L1;
    AllLevels[1] = Images.L2;
    AllLevels[2] = Images.L3;
    AllLevels[3] = Images.L4;
    AllLevels[4] = Images.L5;
    AllLevels[5] = Images.L6;
    AllLevels[6] = Images.L7;
    AllLevels[7] = Images.L8;
    AllLevels[8] = Images.L9;
    AllLevels[9] = Images.L10;
    AllLevels[10] = Images.L11;
    AllLevels[11] = Images.L12;
    AllLevels[12] = Images.L13;
    AllLevels[13] = Images.L14;
    AllLevels[14] = Images.L15;
    AllLevels[15] = Images.L16;
    AllLevels[16] = Images.L17;
    AllLevels[17] = Images.L18;
    AllLevels[18] = Images.L19;
    AllLevels[19] = Images.L20;
    AllLevels[20] = Images.L21;
    AllLevels[21] = Images.L22;
    AllLevels[22] = Images.L23;
    AllLevels[23] = Images.L24;
    AllLevels[24] = Images.L25;
    AllLevels[25] = Images.L26;

    for(int i=0; i<25; i++) {
        if(States -> Datas.Locks[i]) {
            DrawTexture(AllLevels[i], GetScreenWidth()/2 + (i%5)*144 - 559, ((int) i/5)*114 - 8, WHITE);
            for(int j=0; j<(States -> Datas.Stars[i]); j++) {
                if(j==0) {DrawTexture(Images.bronze, GetScreenWidth()/2 + (i%5)*145 - 467 + j*30, ((int) i/5)*114 +40, WHITE);}
                if(j==1) {DrawTexture(Images.gold, GetScreenWidth()/2 + (i%5)*145 - 467 + j*30, ((int) i/5)*114 +40, WHITE);}
                if(j==2) {DrawTexture(Images.diamond, GetScreenWidth()/2 + (i%5)*145 - 467 + j*30, ((int) i/5)*114 +40, WHITE);}
            }
            for(int j=(States -> Datas.Stars[i]); j<3; j++) {
                DrawTexture(Images.gold, GetScreenWidth()/2 + (i%5)*145 - 467 + j*30, ((int) i/5)*114 +40, BLACK);
            }
        } else {
            DrawTexture(AllLevels[i], GetScreenWidth()/2 + (i%5)*144 - 559, ((int) i/5)*114 - 8, BLACK);
        }
    }
    if(States -> Datas.Locks[25]) {
        DrawTexture(AllLevels[25], GetScreenWidth()/2 - 271, + 562, WHITE);
        for(int j=0; j<(States -> Datas.Stars[25]); j++) {
            if(j==0) {DrawTexture(Images.bronze, GetScreenWidth()/2 -177 + j*30, 610, WHITE);}
            if(j==1) {DrawTexture(Images.gold, GetScreenWidth()/2 -177 + j*30, 610, WHITE);}
            if(j==2) {DrawTexture(Images.diamond, GetScreenWidth()/2 -177 + j*30, 610, WHITE);}
        }
        for(int j=(States -> Datas.Stars[25]); j<3; j++) {
            DrawTexture(Images.gold, GetScreenWidth()/2 -177 + j*30, 610, BLACK);
        }
    } else {
        DrawTexture(AllLevels[25], GetScreenWidth()/2 - 271, + 562, BLACK);
    }

    IsMouseOnImagesL(States, Images, clickS);
}

void DrawBackgroundS(AllImages Images, GameState* States, Sound clickS) {
    DrawTexture(Images.background, 0, 0, WHITE);
    DrawTexture(Images.groundS, GetScreenWidth()/2 - 370, + 2, WHITE);
    DrawTexture(Images.arrowS, GetScreenWidth()/2 - 540, - 165, WHITE);
    
    DrawText(TextFormat("%d", States -> Datas.coin), 945, 58, 20, GOLD);

    DrawText("250$", 918, 180, 20, WHITE);
    DrawText("300$", 918, 298, 20, WHITE);
    DrawText("350$", 918, 416, 20, WHITE);
    DrawText("400$", 918, 534, 20, WHITE);
    DrawText("450$", 918, 652, 20, WHITE);
    
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[0]), 460, 181, 20, WHITE);
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[1]), 460, 297, 20, WHITE);
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[2]), 460, 415, 20, WHITE);
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[3]), 460, 533, 20, WHITE);
    DrawText(TextFormat("%d", States -> Datas.FeatureCount[4]), 460, 650, 20, WHITE);
    
    IsMouseOnImagesS(States, Images, clickS);
}

void SetBlock(floorBlock *Block, float x, float y) {
    Block -> length = 72;
    Block -> loc = (Vector2) {x/2, y/2 - 20};
    Block -> color = {173, 168, 174, 255};
    Block -> statue = false;
    Block -> floor = true;
    Block -> hold = false;
    Block -> isclose = false;
    for(int i=0; i<24; i++) {
        Block -> Highers[i] = 0;
    }
}

void SetEmptyData(SavedData *Datas) {
    Datas->coin = 0;
    Datas->framecounter = 0;
    Datas->lettercount = 0;
    Datas->picture = 1;
    Datas->voice = 1;
    Datas->IsSoundOff = false;
    Datas->mouseOnText = false;

    for(int i=0; i<26; i++) {
        if(i<5) {
            Datas->FeatureCount[i] = 0;
        }
        if(i == 1) { Datas->FeatureCount[i] = 5; }
        Datas->Stars[i]=0;
        Datas->Locks[i] = (i == 0);
    }

    Datas -> textBox = {518, 90, 66, 20};
}

void SetGameState(GameState *States, int n) {
    States -> height = 1366;
    States -> width = 768;
    States -> current_time = 0;
    States -> score = 0;
    States -> moveCount = 0;
    States -> selected = 0;
    States -> size = 33;
    States -> level = n;
    States -> PerviousScreen = HADES; //
    States -> CurrentScreen = HADES;
    States -> SettingsHold = false;
    States -> BagHold = false;
    States -> ProfilHold = false;
    States -> BagHold = false;
    States -> exit = false;

    int SCORE_GOALS[26] = {100, 100, 100, 100, 100, 200, 200, 200, 200, 200, 150, 150, 100, 80, 80, 250, 250, 400, 400, 500, 200, 200, 200, 200, 200, 200};
    int MOVE_GOALS[26] = {70, 65, 65, 65, 65, 60, 60, 55, 55, 55, 45, 45, 40, 40, 45, 45 , 45 , 80, 80, 80, 30, 25, 25, 19, 18, 15};
    float TIME_GOALS[26] = {10.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 130.0, 110.0, 110.0, 110.0 , 90.0, 80.0, 80.0, 70.0, 80.0, 80.0, 140.0, 140.0, 55.0, 55.0, 50.0, 50.0, 50.0, 45.0};
    
    States -> score_goal = SCORE_GOALS[n-1];
    States -> move_goal = MOVE_GOALS[n-1];
    States -> time_goal = TIME_GOALS[n-1];
    floorBlock CenterBlock;
    
    SetBlock(&CenterBlock, States -> height, States ->width);
    MakeFloorBlockList(States -> Blocks, States -> size, CenterBlock);
    MakeRandomBlock(States -> ChosenBlock, States -> level);

    switch(n) {
        case 6:
            DeleteBlock(States->Blocks, States->size, 9);
            break;
        case 7:
            DeleteBlock(States->Blocks, States->size, 9);
            break;
        case 8:
            DeleteBlock(States->Blocks, States->size, 9);
            break;
        case 11:
            DeleteBlock(States->Blocks, States->size, 4);
            DeleteBlock(States->Blocks, States->size, 11);
            DeleteBlock(States->Blocks, States->size, 12);
            break;
        case 12:
            DeleteBlock(States->Blocks, States->size, 6);
            DeleteBlock(States->Blocks, States->size, 7);
            DeleteBlock(States->Blocks, States->size, 14);
            break;
        case 13:
            DeleteBlock(States->Blocks, States->size, 6);
            DeleteBlock(States->Blocks, States->size, 7);
            DeleteBlock(States->Blocks, States->size, 11);
            DeleteBlock(States->Blocks, States->size, 12);
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 5, 3);
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 15, 0);
            break;
        case 14:
            DeleteBlock(States->Blocks, States->size, 0);
            DeleteBlock(States->Blocks, States->size, 6);
            DeleteBlock(States->Blocks, States->size, 7);
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 5, 3);
            break;
        case 15:
            DeleteBlock(States->Blocks, States->size, 11);
            DeleteBlock(States->Blocks, States->size, 12);
            DeleteBlock(States->Blocks, States->size, 18);
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 15, 0);
            break;
        case 16:
            DeleteBlock(States->Blocks, States->size, 8);
            DeleteBlock(States->Blocks, States->size, 10);
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 5, 3);
            AddBlock(States->Blocks, States->size, 0, 2);
            AddBlock(States->Blocks, States->size, 0, 4);
            break;
        case 17:
            DeleteBlock(States->Blocks, States->size, 8);
            DeleteBlock(States->Blocks, States->size, 10);
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 15, 0);
            AddBlock(States->Blocks, States->size, 18, 1);
            AddBlock(States->Blocks, States->size, 18, 5);
            break;
        case 18:
            DeleteBlock(States->Blocks, States->size, 7);
            DeleteBlock(States->Blocks, States->size, 11);
            AddBlock(States->Blocks, States->size, 1, 3);
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 3, 4);
            AddBlock(States->Blocks, States->size, 3, 5);
            AddBlock(States->Blocks, States->size, 15, 0);
            AddBlock(States->Blocks, States->size, 15, 1);
            AddBlock(States->Blocks, States->size, 15, 2);
            AddBlock(States->Blocks, States->size, 17, 0);
            break;
        case 19:
            DeleteBlock(States->Blocks, States->size, 6);
            DeleteBlock(States->Blocks, States->size, 12);
            AddBlock(States->Blocks, States->size, 2, 3);
            AddBlock(States->Blocks, States->size, 5, 1);
            AddBlock(States->Blocks, States->size, 5, 2);
            AddBlock(States->Blocks, States->size, 5, 3);
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 13, 4);
            AddBlock(States->Blocks, States->size, 13, 5);
            AddBlock(States->Blocks, States->size, 16, 0);
            break;
        case 20:
            DeleteBlock(States->Blocks, States->size, 4);
            DeleteBlock(States->Blocks, States->size, 14);
            AddBlock(States->Blocks, States->size, 5, 0);
            AddBlock(States->Blocks, States->size, 5, 1);
            AddBlock(States->Blocks, States->size, 5, 2);
            AddBlock(States->Blocks, States->size, 5, 3);
            AddBlock(States->Blocks, States->size, 15, 0);
            AddBlock(States->Blocks, States->size, 15, 1);
            AddBlock(States->Blocks, States->size, 15, 2);
            AddBlock(States->Blocks, States->size, 15, 3);
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 3, 4);
            AddBlock(States->Blocks, States->size, 3, 5);
            AddBlock(States->Blocks, States->size, 13, 4);
            AddBlock(States->Blocks, States->size, 13, 5);
            AddBlock(States->Blocks, States->size, 13, 6);
            break;
        case 22:
            AddBlock(States->Blocks, States->size, 3, 3);
            AddBlock(States->Blocks, States->size, 5, 3);
            break;
        case 23:
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 15, 0);
            break;
        case 24:
            AddBlock(States->Blocks, States->size, 13, 0);
            AddBlock(States->Blocks, States->size, 15, 0);
            AddBlock(States->Blocks, States->size, 17, 0);
            break;
        case 26:
            DeleteBlock(States->Blocks, States->size, 0);
            DeleteBlock(States->Blocks, States->size, 3);
            DeleteBlock(States->Blocks, States->size, 4);
            DeleteBlock(States->Blocks, States->size, 5);
            DeleteBlock(States->Blocks, States->size, 8);
            DeleteBlock(States->Blocks, States->size, 10);
            DeleteBlock(States->Blocks, States->size, 13);
            DeleteBlock(States->Blocks, States->size, 14);
            DeleteBlock(States->Blocks, States->size, 10);
            break;
    }
}

void OpenLevels(GameState *States) {
    int count = 0;
    for(int i=0; i<25; i++) {
        if(States -> Datas.Stars[i] > 0 && States -> Datas.Locks[i]) {
            States -> Datas.Locks[i+1] = true;
        }
        count += States -> Datas.Stars[i];
    }

    if(count == 75) {States -> Datas.Locks[25] = true;} //75 olmalı count==75
}

void MakeHexagon(floorBlock Block) {

    if(Block.floor) {
        DrawPoly(Block.loc, 6, Block.length/2, 0, BLACK);
        DrawPoly(Block.loc, 6, Block.length/2 - 1, 0, Block.color);
    }

    int *BlockPtr = Block.Highers;
    Color color;
    int i = 1;

    while(*BlockPtr != 0) {
        
        switch(*BlockPtr) {
            case 1:
                color = DARKBLUE;
                break;
            case 2:
                color = YELLOW;
                break;
            case 3:
                color = RED;
                break;
            case 4:
                color = GREEN;
                break;
            case 5:
                color = VIOLET;
                break;
            case 6:
                color = ORANGE;
                break;
            case 7:
                color = PINK;
                break;
            case 8:
                color = SKYBLUE;
                break;
            case 9:
                color = MAGENTA;
                break;
            case 10:
                color = DARKGRAY;
                break;
        }

        if(Block.statue) {
            if(Block.floor) {
                color.a = 100;
            } else {
                ColorChange(&color);
            }
        }

        if(!Block.floor) {
            DrawPoly((Vector2){Block.loc.x, Block.loc.y - 5*(i-1)}, 6, Block.length/2, 0, BLACK);
            DrawPoly((Vector2){Block.loc.x, Block.loc.y - 5*(i-1)}, 6, Block.length/2 - 1, 0, color);
        } else {
            DrawPoly((Vector2){Block.loc.x, Block.loc.y - 5*i}, 6, Block.length/2, 0, BLACK);
            DrawPoly((Vector2){Block.loc.x, Block.loc.y - 5*i}, 6, Block.length/2 - 1, 0, color);
        }

        i++;
        BlockPtr++;
    }
}

void MakeHexagonMore(floorBlock Blocks[], int n) {
    int limit;

    
    if(n>19) {
        limit = 19;
    } else {
        limit = n;
    }

    for(int i=0; i<limit; i++) {
        if(Blocks[i].hold || Blocks[i].isclose || Blocks[i].loc.x == 0) {
            continue;
        } else{
            for(int j=19; j<n; j++) {
                if(Blocks[j].length == 60 || Blocks[j].loc.x == 0) {
                    continue;
                }

                if(Blocks[i].loc.y > Blocks[j].loc.y) {
                    MakeHexagon(Blocks[j]);
                    Blocks[j].length = 60;
                }

                if(Blocks[i].loc.y == Blocks[j].loc.y && Blocks[i].loc.x > Blocks[j].loc.x) {
                    MakeHexagon(Blocks[j]);
                    Blocks[j].length = 60;
                }
            }
            
            MakeHexagon(Blocks[i]);
        }
    }

    for(int i=19; i<n; i++) {
        if(Blocks[i].length == 72 && Blocks[i].loc.x != 0) {
            MakeHexagon(Blocks[i]);
        }
        Blocks[i].length = 72;
    }

    for(int i=0; i<n; i++) {
        if(Blocks[i].hold) {
            MakeHexagon(Blocks[i]);
        }
    }
}

void MakeFloorBlockList(floorBlock Blocks[], int n, floorBlock Block) {
    Blocks[0] = Block;
    
    for(int i=1; i<n; i++) {
        Blocks[i].color = Block.color;
        Blocks[i].length = Block.length;
        Blocks[i].statue = false;
        Blocks[i].floor = true;
        Blocks[i].hold = false;
        Blocks[i].isclose = false;

        for(int j=0; j<24; j++) {
            Blocks[i].Highers[j] = 0;
        }

        Blocks[i].loc.x = 0;
        Blocks[i].loc.y = 0;
    }


    for(int i=0; i<6; i++) {
        Blocks[i+1].loc.x = round(Block.loc.x + Block.length*sin(PI*i/3)*(sqrt(3)/2));
        Blocks[i+1].loc.y = round(Block.loc.y + Block.length*cos(PI*i/3)*(sqrt(3)/2));
    }

    floorBlock *fPtr = &Blocks[0];
    Vector2 tempVec;
    bool check;

    for(int i=1; i<7; i++) {
        for(int k=0; k<6; k++) {
            check = true;
            tempVec.x = round(Blocks[i].loc.x + Block.length*sin(PI*k/3)*(sqrt(3)/2));
            tempVec.y = round(Blocks[i].loc.y + Block.length*cos(PI*k/3)*(sqrt(3)/2));
        
            while(fPtr->loc.x != 0) {
                if(fPtr->loc.x == tempVec.x && fPtr->loc.y == tempVec.y) {
                    check = false;
                }
                fPtr++;
            }

            if(check) {
                fPtr->loc.x = tempVec.x;
                fPtr->loc.y = tempVec.y;
            }

            fPtr = &Blocks[0];
        }
    }

    mixList(Blocks, 19);
}

void MakeRandomBlock(floorBlock Lefts[], int level) {
    int colors[18];
    RandomColor(colors, (int) ((level-1)/5 + 5));

    for(int i=0; i<3; i++) {

        switch(colors[i*6]) {
            case 1:
                Lefts[i].color = DARKBLUE;
                break;
            case 2:
                Lefts[i].color = YELLOW;
                break;
            case 3:
                Lefts[i].color = RED;
                break;
            case 4:
                Lefts[i].color = GREEN;
                break;
            case 5:
                Lefts[i].color = VIOLET;
                break;
            case 6:
                Lefts[i].color = ORANGE;
                break;
            case 7:
                Lefts[i].color = PINK;
                break;
            case 8:
                Lefts[i].color = SKYBLUE;
                break;
            case 9:
                Lefts[i].color = MAGENTA;
                break;
            case 10:
                Lefts[i].color = DARKGRAY;
                break;
        }
        
        for(int j=0; j<6; j++) {
            Lefts[i].Highers[j] = colors[i*6+j];
        }
        
        for(int j=6; j<24; j++) {
            Lefts[i].Highers[j] = 0;
        }

        Lefts[i].length = 72;
        Lefts[i].statue = false;
        Lefts[i].floor = false;
        Lefts[i].hold = false;
        Lefts[i].isclose = false;
        Lefts[i].loc.x = 580 + 100 * i;
        Lefts[i].loc.y = 640;
    }
}

void RandomColor(int colors[], int n) {
    int newColor1, newColor2, newColor3, change1, change2;

    for(int i=0; i<18; i++) {
        colors[i] = 0;
    }

    for(int i=0; i<3; i++) {
        newColor1 = (rand()%n)+1;
        newColor2 = rand()%(n+1);
        newColor3 = rand()%(n+1);

        if(newColor2 == 0 && newColor3 == 0) {
            colors[i*6] = newColor1;
            colors[i*6 +1] = newColor1;
        } else {
            if(newColor2 == 0 || newColor3 == 0) {
                change1 = (rand()%3)+1;
                for(int j=0; j<change1; j++) {
                    colors[i*6 + j] = newColor1;
                }
                for(int j=change1; j<4; j++) {
                    colors[i*6 + j] = newColor2+newColor3;
                }
            } else {
                change1 = (rand()%4)+1;
                change2 = (rand()%(5-change1))+change1+1;
                for(int j=0; j<change1; j++) {
                    colors[i*6 + j] = newColor1;
                }
                for(int j=change1; j<change2; j++) {
                    colors[i*6 + j] = newColor2;
                }
                for(int j=change2; j<6; j++) {
                    colors[i*6 + j] = newColor3;
                }
            }
        }
    }
}

void TurnWhite(floorBlock Blocks[], int n) {
    int x = GetMouseX();
    int y = GetMouseY();

    for(int i=0; i<n; i++) {
        Blocks[i].color = {173, 168, 174, 255};
        Blocks[i].statue = false;
        TurnStatue(&Blocks[i], x, y);
    }

    for(int i=0; i<n; i++) {
        if(Blocks[i].statue) {
            Blocks[i].color = {205, 205, 205, 255};
        }
    }

}

void TurnStatue(floorBlock *Block, int m, int n) {
    bool c1 = (Block -> loc.y - (Block -> length/2)*sin(PI/3)) < n;
    bool c2 = (n - Block -> loc.y) > (tan(2*PI/3)*(m - Block -> loc.x + (Block -> length/2)));
    bool c3 = (n - Block -> loc.y) < (tan(PI/3)*(m - Block -> loc.x + (Block -> length/2)));
    bool c4 = (n - Block -> loc.y) > (tan(PI/3)*(m - Block -> loc.x - (Block -> length/2)));
    bool c5 = (n - Block -> loc.y) < (tan(2*PI/3)*(m - Block -> loc.x - (Block -> length/2)));
    bool c6 = n < (Block -> loc.y + (Block -> length/2)*sin(PI/3));

    if(c1 && c2 && c3 && c4 && c5 && c6) {
        Block -> statue = true;
    }
}

void ColorChange(Color *color) {
    if((color -> r == DARKBLUE_2.r) && (color -> g == DARKBLUE_2.g) && (color -> b == DARKBLUE_2.b)) {
        *color = DARKBLUE;
    }

    if((color -> r == YELLOW_2.r) && (color -> g == YELLOW_2.g) && (color -> b == YELLOW_2.b)) {
        *color = YELLOW;
    }

    if((color -> r == GREEN_2.r) && (color -> g == GREEN_2.g) && (color -> b == GREEN_2.b)) {
        *color = GREEN;
    }

    if((color -> r == RED_2.r) && (color -> g == RED_2.g) && (color -> b == RED_2.b)) {
        *color = RED;
    }

    if((color -> r == VIOLET_2.r) && (color -> g == VIOLET_2.g) && (color -> b == VIOLET_2.b)) {
        *color = VIOLET;
    }

    if((color -> r == ORANGE_2.r) && (color -> g == ORANGE_2.g) && (color -> b == ORANGE_2.b)) {
        *color = ORANGE;
    }

    if((color -> r == PINK_2.r) && (color -> g == PINK_2.g) && (color -> b == PINK_2.b)) {
        *color = PINK;
    }

    if((color -> r == SKYBLUE_2.r) && (color -> g == SKYBLUE_2.g) && (color -> b == SKYBLUE_2.b)) {
        *color = SKYBLUE;
    }

    if((color -> r == MAGENTA_2.r) && (color -> g == MAGENTA_2.g) && (color -> b == MAGENTA_2.b)) {
        *color = MAGENTA;
    }

    if((color -> r == DARKGRAY_2.r) && (color -> g == DARKGRAY_2.g) && (color -> b == DARKGRAY_2.b)) {
        *color = DARKGRAY;
    }

    if((color -> r == DARKBLUE.r) && (color -> g == DARKBLUE.g) && (color -> b == DARKBLUE.b)) {
        *color = DARKBLUE_2;
    }

    if((color -> r == YELLOW.r) && (color -> g == YELLOW.g) && (color -> b == YELLOW.b)) {
        *color = YELLOW_2;
    }

    if((color -> r == GREEN.r) && (color -> g == GREEN.g) && (color -> b == GREEN.b)) {
        *color = GREEN_2;
    }

    if((color -> r == RED.r) && (color -> g == RED.g) && (color -> b == RED.b)) {
        *color = RED_2;
    }

    if((color -> r == VIOLET.r) && (color -> g == VIOLET.g) && (color -> b == VIOLET.b)) {
        *color = VIOLET_2;
    }

    if((color -> r == ORANGE.r) && (color -> g == ORANGE.g) && (color -> b == ORANGE.b)) {
        *color = ORANGE_2;
    }

    if((color -> r == PINK.r) && (color -> g == PINK.g) && (color -> b == PINK.b)) {
        *color = PINK_2;
    }

    if((color -> r == SKYBLUE.r) && (color -> g == SKYBLUE.g) && (color -> b == SKYBLUE.b)) {
        *color = SKYBLUE_2;
    }

    if((color -> r == MAGENTA.r) && (color -> g == MAGENTA.g) && (color -> b == MAGENTA.b)) {
        *color = MAGENTA_2;
    }

    if((color -> r == DARKGRAY.r) && (color -> g == DARKGRAY.g) && (color -> b == DARKGRAY.b)) {
        *color = DARKGRAY_2;
    }
}

void HoldHexa(GameState *States, Sound pick, Sound put) {
    int pos_x = GetMouseX();
    int pos_y = GetMouseY();

    for(int i=0; i<3; i++) {
        (*States).ChosenBlock[i].statue = false;
    }

    floorBlock *BlockPtr = &(*States).ChosenBlock[0];
    int *ColorPtr;

    for(int i=0; i<3; i++) {
        ColorPtr = BlockPtr -> Highers;
        int j = 0;
        
        while(*ColorPtr != 0) {
            TurnStatue(BlockPtr, pos_x, pos_y+(j*5));
            j++;
            ColorPtr++;
        }
        BlockPtr++;
        
    }

    for(int i=0; i<3; i++) {
        if((*States).ChosenBlock[i].hold && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int index = WhichFloorIsMouseOn((*States).Blocks, (*States).size);
            
            if(index == -1) {
                (*States).ChosenBlock[i].hold = false;
                (*States).ChosenBlock[i].loc.x = 580 + 100 * i;
                (*States).ChosenBlock[i].loc.y = 640;
            } else if((*States).Blocks[index].isclose) {
                (*States).ChosenBlock[i].hold = false;
                (*States).ChosenBlock[i].loc.x = 580 + 100 * i;
                (*States).ChosenBlock[i].loc.y = 640;
            } else if(IsPlaceable((*States).Blocks[index])) {
                for(int j=0; j<6; j++) {
                    (*States).Blocks[index].Highers[j] = (*States).ChosenBlock[i].Highers[j];
                    (*States).ChosenBlock[i].Highers[j] = 0;
                }

                (*States).ChosenBlock[i].hold = false;
                (*States).ChosenBlock[i].loc.x = 580 + 100 * i;
                (*States).ChosenBlock[i].loc.y = 640;

                OrganiseBlocks((*States).Blocks, (*States).size, index, &(*States).score);
                (*States).moveCount += 1;
                if((*States).Datas.IsSoundOff == false) {PlaySound(put);}

                if(IsEmpty((*States).ChosenBlock)) {
                    MakeRandomBlock((*States).ChosenBlock, (*States).level);
                }
            }
        }
        if((*States).ChosenBlock[i].hold) {
            (*States).ChosenBlock[i].loc.x = pos_x + (*States).ChosenBlock[i].length/2;
            (*States).ChosenBlock[i].loc.y = pos_y - (*States).ChosenBlock[i].length/3;
        }
        if((*States).ChosenBlock[i].statue && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            (*States).ChosenBlock[i].hold = true;
            if((*States).Datas.IsSoundOff == false) {PlaySound(pick);}
        }
    }
}

void OrganiseBlocks(floorBlock Blocks[], int n, int index, int *score) {
    int index2;
    float pos_x, pos_y;
    
    for(int i=0; i<6; i++) {
        pos_x = round(Blocks[index].loc.x + Blocks[index].length*sin(PI*i/3)*(sqrt(3)/2));
        pos_y = round(Blocks[index].loc.y + Blocks[index].length*cos(PI*i/3)*(sqrt(3)/2));
        index2 = GiveMeIndex(Blocks, n, pos_x, pos_y);

        if(index2 == -1) {
            continue;
        }

        if(  (TheLastColor(Blocks[index2]) == 0)   ||   (TheLastColor(Blocks[index]) != TheLastColor(Blocks[index2]))  ) {
            continue;
        } else {
            ChangeBlocks(Blocks[index2].Highers, Blocks[index].Highers, score);
            OrganiseBlocks(Blocks, n, index, score);
            OrganiseBlocks(Blocks, n, index2, score);
            break;
        }
    }
}

void ChangeBlocks(int *Block1, int *Block2, int *score) {
    int *B1Ptr = Block1;
    int *B2Ptr = Block2;

    while(*B1Ptr != 0) {
        B1Ptr++;
    }

    while(*B2Ptr != 0) {
        B2Ptr++;
    }

    B1Ptr--;
    int color = *B1Ptr;

    while(*B1Ptr == color) {
        *B2Ptr = color;
        B2Ptr++;
        *B1Ptr = 0;
        B1Ptr--;
    }

    B2Ptr--;
    int count = 0;

    while(*B2Ptr == color) {
        count++;
        B2Ptr--;
    }

    B2Ptr++;

    if(count >= 10) {
        while(*B2Ptr == color) {
            *B2Ptr = 0;
            B2Ptr++;
        }
        (*score) += count;
    }
}

void CloseBlock(floorBlock *Block, int n, int *score) {
    if(*score < n) {
        Block -> isclose = true;
        if((n - (*score)) < 100) {    
            char a1 = (n - (*score))/10 + '0';
            char a2 = (n - (*score))%10 + '0';
            char count[3] = {a1, a2, '\0'};
            DrawPoly(Block -> loc, 6, 36, 0, BLACK);
            DrawPoly(Block -> loc, 6, 35, 0, (Color){97, 95, 97, 255});
            DrawText(count, Block -> loc.x - 12, Block -> loc.y - 9, 24, (Color){205, 205, 205, 255});
        } else {
            char a3 = (n - (*score))%10 + '0';
            char a2 = ( (n - (*score)) /10 ) % 10 + '0';
            char a1 = (n - (*score))/100 + '0';
            char count[4] = {a1, a2, a3, '\0'};
            DrawPoly(Block -> loc, 6, 36, 0, BLACK);
            DrawPoly(Block -> loc, 6, 35, 0, (Color){97, 95, 97, 255});
            DrawText(count, Block -> loc.x - 19, Block -> loc.y - 9, 24, (Color){205, 205, 205, 255});
        }
        
    } else {
        Block -> isclose = false;
    }
}

void mixList(floorBlock Blocks[], int n) {
    
    floorBlock tempBlock;
    
    for(int k=0; k<18; k++) {
        for(int i=0; i<18-k; i++) {
            if(Blocks[i].loc.y == Blocks[i+1].loc.y) {
                if(Blocks[i].loc.x > Blocks[i+1].loc.x) {
                    tempBlock = Blocks[i];
                    Blocks[i] = Blocks[i+1];
                    Blocks[i+1] = tempBlock;
                }
            }
            
            if(Blocks[i].loc.y > Blocks[i+1].loc.y) {
                tempBlock = Blocks[i];
                Blocks[i] = Blocks[i+1];
                Blocks[i+1] = tempBlock;
            }
        }
    }

    for(int k=0; k<(n-20); k++) {
        for(int i=19; i<(n-k-1); i++) {
            if(Blocks[i+1].loc.y == 0) {
                continue;
            }
            
            if(Blocks[i].loc.y == Blocks[i+1].loc.y) {
                if(Blocks[i].loc.x > Blocks[i+1].loc.x) {
                    tempBlock = Blocks[i];
                    Blocks[i] = Blocks[i+1];
                    Blocks[i+1] = tempBlock;
                }
            }
            
            if(Blocks[i].loc.y > Blocks[i+1].loc.y) {
                tempBlock = Blocks[i];
                Blocks[i] = Blocks[i+1];
                Blocks[i+1] = tempBlock;
            }
        }
    }
}

void InitName(SavedData *Datas) {
    if(CheckCollisionPointRec(GetMousePosition(), Datas->textBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Datas->mouseOnText = true;
    }
    if(!CheckCollisionPointRec(GetMousePosition(), Datas->textBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Datas->mouseOnText = false;
    }

    if(Datas->mouseOnText){
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        int key = GetCharPressed();

        if(key > 0){
            if ((key >= 32) && (key <= 125) && (Datas->lettercount < 8)){
                Datas->name[Datas->lettercount] = (char)key;
                Datas->name[Datas->lettercount+1] = '\0';
                Datas->lettercount++;
            }
        }

        if (IsKeyPressed(KEY_BACKSPACE)){
        
            Datas->lettercount--;
            if (Datas->lettercount < 0) Datas->lettercount = 0;
            Datas->name[Datas->lettercount] = '\0';

        }
    }else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if(Datas->mouseOnText) {Datas->framecounter++;}
    else {Datas->framecounter = 0;}
}

void UseFeature(GameState *States) {
    switch(States -> selected) {
        case 0:
            break;
        case 1:
            if(States -> moveCount >= 20) {States -> moveCount -= 20;}
            States -> selected = 0;
            break;
        case 2:
            MakeRandomBlock(States -> ChosenBlock, States -> level);
            States -> selected = 0;
            break;
        case 3:
            if(!(IsMouseButtonDown(MOUSE_BUTTON_LEFT))) {break;}
            else {
                int index = WhichFloorIsMouseOn(States -> Blocks, States -> size);
                if(index == -1) {break;}
                else {
                    for(int i=0; i<24; i++) { States -> Blocks[index].Highers[i] = 0;}
                    break;
                }
            }
        case 4:
            if(States -> current_time >= 40) {States -> current_time -= 40;}
            States -> selected = 0;
            break;
    }
}

bool IsPlaceable(floorBlock Block) {
    if(Block.Highers[0] == 0 && (!Block.isclose) && Block.loc.x != 0) {
        return true;
    } else {
        return false;
    }
}

bool IsEmpty(floorBlock Blocks[]) {
    for(int i=0; i<3; i++) {
        if(Blocks[i].Highers[0] != 0) {
            return false;
        }
    }

    return true;
}

bool IsOver(floorBlock Blocks[], int n) {
    for(int i=0; i<n; i++) {
        if(IsPlaceable(Blocks[i])) {
            return false;
        }
    }

    return true;
}

int IsFinished(GameState State, int n) {
    int count = 0;
    
    for(int i=(5*n); i<(5*(n+1)); i++) {
        count += State.Datas.Stars[i];
    }

    if(count<3) return 0;
    if(count<6) return 1;
    if(count<9) return 2;
    if(count<12) return 3;
    if(count<15) return 4;
    if(count == 15) return 5;

    return -1;
}

int DeleteBlock(floorBlock Blocks[], int n, int index) {
    if(index >= n) {
        return 0;
    }

    if(Blocks[index].loc.x == 0) {
        return 0;
    }

    Blocks[index].isclose = true;
    return 0;
}

int AddBlock(floorBlock Blocks[], int n, int index, int rotation) {
    if(index >= n) {
        return 0;
    }

    if(Blocks[index].loc.x == 0 || Blocks[n-1].loc.x != 0) {
        return 0;
    }

    floorBlock *BlockPtr = Blocks;
    Vector2 tempVec;

    tempVec.x = round(Blocks[index].loc.x + Blocks[index].length*sin(PI*rotation/3)*(sqrt(3)/2));
    tempVec.y = round(Blocks[index].loc.y + Blocks[index].length*cos(PI*rotation/3)*(sqrt(3)/2));

    for(int i=0; i<n; i++) {
        if(Blocks[i].loc.x == tempVec.x && Blocks[i].loc.y == tempVec.y) {
            return 0;
        }
    }

    while((*BlockPtr).loc.x != 0) {
        BlockPtr++;
    }

    BlockPtr -> color = Blocks[index].color;
    BlockPtr -> length = Blocks[index].length;
    BlockPtr -> statue = false;
    BlockPtr -> floor = true;
    BlockPtr -> hold = false;
    BlockPtr -> isclose = false;

    for(int i=0; i<24; i++) {
        (*BlockPtr).Highers[i] = 0;
    }

    BlockPtr -> loc.x = tempVec.x;
    BlockPtr -> loc.y = tempVec.y;
    
    mixList(Blocks, n);

    return 0;
}

int WhichFloorIsMouseOn(floorBlock Blocks[], int n) {
    for(int i=0; i<n; i++) {
        if(Blocks[i].statue) {
            return i;
        }
    }
    
    return -1;
}

int TheLastColor(floorBlock Block) {
    if(Block.Highers[0] == 0) {
        return 0;
    }

    int x = 0;

    for(int i=23; i>=0; i--) {
        if(Block.Highers[i] != 0) {
            x = Block.Highers[i];
            break;
        }
    }

    return x;
}

int GiveMeIndex(floorBlock Blocks[], int n, float pos_x, float pos_y) {
    Vector2 position;
    
    for(int i=0; i<n; i++) {
        position.x = Blocks[i].loc.x;
        position.y = Blocks[i].loc.y;
        
        if(position.x == pos_x && position.y == pos_y) {
            return i;
        }
    }

    return -1;
}

int EndScreen(GameState *States, int n, AllImages Images, bool win, Sound clickS) {
    DrawRectangleRec((Rectangle){0, 0, (States -> height), (States -> width)}, PURPLE);
    DrawTexture(Images.groundG2, GetScreenWidth()/2 - 185, 0, WHITE);
    DrawTexture(Images.timer2, GetScreenWidth()/2 - 165, + 230, WHITE);
    DrawTexture(Images.move2, GetScreenWidth()/2 - 200, + 300, WHITE);
    DrawTexture(Images.cup, GetScreenWidth()/2 - 160, + 450, WHITE);
    DrawTexture(Images.coinG, GetScreenWidth()/2 - 220, + 500, WHITE);
    DrawTexture(Images.go, GetScreenWidth()/2 +50, + 610, WHITE);

    int starcount = 0;

    if(win) {
        if(starcount == 0) {
            starcount += 1;
            if(States -> moveCount < States -> move_goal) {starcount += 1;}
            if(States -> current_time < States -> time_goal) {starcount += 1;}
            States -> Datas.coin += 15*(States -> level);
        }

        DrawTexture(Images.bronzeG,GetScreenWidth()/2 - 145, + 80, BLACK);
        DrawTexture(Images.goldG, GetScreenWidth()/2 - 45, + 80, BLACK);
        DrawTexture(Images.diamondG, GetScreenWidth()/2 + 55, + 80, BLACK);
        
        if(starcount > 0) DrawTexture(Images.bronzeG, GetScreenWidth()/2 - 145, + 80,WHITE);
        if(starcount > 1) DrawTexture(Images.goldG, GetScreenWidth()/2 - 45, + 80, WHITE);
        if(starcount > 2) DrawTexture(Images.diamondG, GetScreenWidth()/2 + 55, + 80, WHITE);
        
        DrawText("YOU WIN", (States->height) / 2 - 120, (States->width) / 2 -350, 60, GOLD);

        DrawText(TextFormat("%.2d:%.2d:%.2d", (int) States->current_time/60, (int) States->current_time%60, (int) (States->current_time*100)%60), 620, 255, 30, BLACK);
        DrawText(TextFormat("%d", States->moveCount), 620, 365, 30, BLACK);      
        DrawText(TextFormat("%d", States->score), 620, 475, 30, BLACK);
        DrawText(TextFormat("%d", 15*(States -> level)), 620, 585, 30, BLACK);
    } else {
        DrawTexture(Images.bronzeG,GetScreenWidth()/2 - 145, + 80, BLACK);
        DrawTexture(Images.goldG, GetScreenWidth()/2 - 45, + 80, BLACK);
        DrawTexture(Images.diamondG, GetScreenWidth()/2 + 55, + 80, BLACK);
        
        DrawText("YOU LOST", (States->height) / 2 - 120, (States->width) / 2 -350, 60, GOLD);

        DrawText(TextFormat("%.2d:%.2d:%.2d", (int) States->current_time/60, (int) States->current_time%60, (int) (States->current_time*100)%60), 620, 255, 30, BLACK);
        DrawText(TextFormat("%d", States->moveCount), 620, 365, 30, BLACK);      
        DrawText(TextFormat("%d", States->score), 620, 475, 30, BLACK);
        DrawText(TextFormat("%d", 0), 620, 585, 30, BLACK);
    }

    Vector2 Position = GetMousePosition();

    if(Position.x > GetScreenWidth()/2+110 && Position.x < GetScreenWidth()/2+200 && Position.y > 685 && Position.y < 740) {
        DrawTexture(Images.go, GetScreenWidth()/2 +50, + 610, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (States -> level == 26) {States -> level = 26;}
            else if(States -> level != 1 && States -> Datas.Locks[States -> level] == false) {States -> Datas.FeatureCount[1] -= 1;}
            OpenLevels(States);
            Screen tempSec = States -> PerviousScreen;
            States -> Datas.voice = 1;
            if(States -> Datas.Stars[States -> level - 1] < starcount) {States -> Datas.Stars[States -> level - 1] = starcount;}
            PlaySound(clickS);
            if(tempSec == BOSS) {
                SetGameState(States, 1);
                States -> CurrentScreen = BOSS;
                States -> PerviousScreen = BOSS;
            } else {
                SetGameState(States, 1);
                States -> CurrentScreen = LEVELS;
                States -> PerviousScreen = tempSec;
            }
        }
    }

    return 0;
}

int GamePlay(GameState *States, AllImages Images, Sound clickS, Sound pick, Sound put) {
    
    DrawBackgroundG(Images, States, clickS);
    TurnWhite(States -> Blocks, States -> size);
    HoldHexa(States, pick, put);

    return 0;
}

int Level(AllImages Images, GameState *States, Sound clickS, Sound pick, Sound put) {
    if(States -> score >= States -> score_goal) {
        EndScreen(States, States -> level, Images, true, clickS);
        return 0;
    }

    if(IsOver(States -> Blocks, States -> size)) {
        EndScreen(States, States -> level, Images, false, clickS);
        return 0;
    }
    
    GamePlay(States, Images, clickS, pick, put);
    
    switch(States -> level) {
        case 2:
            CloseBlock(&(States->Blocks[9]), 10, &(States->score));
            break;
        case 3:
            CloseBlock(&(States->Blocks[9]), 20, &(States->score));
            break;
        case 4:
            CloseBlock(&(States->Blocks[9]), 30, &(States->score));
            break;
        case 5:
            CloseBlock(&(States->Blocks[9]), 50, &(States->score));
            break;
        case 6:
            CloseBlock(&(States->Blocks[4]), 30, &(States->score));
            CloseBlock(&(States->Blocks[14]), 30, &(States->score));
            break;
        case 7:
            CloseBlock(&(States->Blocks[6]), 50, &(States->score));
            CloseBlock(&(States->Blocks[12]), 50, &(States->score));
            break;
        case 8:
            CloseBlock(&(States->Blocks[7]), 50, &(States->score));
            CloseBlock(&(States->Blocks[11]), 50, &(States->score));
            break;
        case 9:
            CloseBlock(&(States->Blocks[6]), 50, &(States->score));
            CloseBlock(&(States->Blocks[7]), 50, &(States->score));
            CloseBlock(&(States->Blocks[9]), 70, &(States->score));
            break;
        case 10:
            CloseBlock(&(States->Blocks[9]), 70, &(States->score));
            CloseBlock(&(States->Blocks[11]), 50, &(States->score));
            CloseBlock(&(States->Blocks[12]), 50, &(States->score));
            break;
        case 14:
            CloseBlock(&(States->Blocks[11]), 20, &(States->score));
            CloseBlock(&(States->Blocks[12]), 20, &(States->score));
            break;
        case 15:
            CloseBlock(&(States->Blocks[6]), 20, &(States->score));
            CloseBlock(&(States->Blocks[7]), 20, &(States->score));
            break;
        case 16:
            CloseBlock(&(States->Blocks[9]), 125, &(States->score));
            CloseBlock(&(States->Blocks[6]), 75, &(States->score));
            CloseBlock(&(States->Blocks[7]), 75, &(States->score));
            CloseBlock(&(States->Blocks[11]), 75, &(States->score));
            CloseBlock(&(States->Blocks[12]), 75, &(States->score));
            break;
        case 17:
            CloseBlock(&(States->Blocks[9]), 125, &(States->score));
            CloseBlock(&(States->Blocks[6]), 75, &(States->score));
            CloseBlock(&(States->Blocks[7]), 75, &(States->score));
            CloseBlock(&(States->Blocks[11]), 75, &(States->score));
            CloseBlock(&(States->Blocks[12]), 75, &(States->score));
            break;
        case 18:
            CloseBlock(&(States->Blocks[5]), 100, &(States->score));
            CloseBlock(&(States->Blocks[9]), 200, &(States->score));
            CloseBlock(&(States->Blocks[13]), 100, &(States->score));
            break;
        case 19:
            CloseBlock(&(States->Blocks[3]), 100, &(States->score));
            CloseBlock(&(States->Blocks[9]), 200, &(States->score));
            CloseBlock(&(States->Blocks[15]), 100, &(States->score));
            break;
        case 20:
            CloseBlock(&(States->Blocks[0]), 150, &(States->score));
            CloseBlock(&(States->Blocks[9]), 250, &(States->score));
            CloseBlock(&(States->Blocks[18]), 150, &(States->score));
            break;
        case 21:
            CloseBlock(&(States->Blocks[6]), 80, &(States->score));
            CloseBlock(&(States->Blocks[7]), 80, &(States->score));
            CloseBlock(&(States->Blocks[11]), 50, &(States->score));
            CloseBlock(&(States->Blocks[12]), 50, &(States->score));
            CloseBlock(&(States->Blocks[14]), 30, &(States->score));
            break;
        case 22:
            CloseBlock(&(States->Blocks[6]), 80, &(States->score));
            CloseBlock(&(States->Blocks[7]), 80, &(States->score));
            CloseBlock(&(States->Blocks[13]), 50, &(States->score));
            CloseBlock(&(States->Blocks[15]), 50, &(States->score));
            CloseBlock(&(States->Blocks[16]), 30, &(States->score));
            CloseBlock(&(States->Blocks[17]), 30, &(States->score));
            CloseBlock(&(States->Blocks[18]), 30, &(States->score));
            break;
        case 23:
            CloseBlock(&(States->Blocks[6]), 80, &(States->score));
            CloseBlock(&(States->Blocks[7]), 80, &(States->score));
            CloseBlock(&(States->Blocks[14]), 50, &(States->score));
            CloseBlock(&(States->Blocks[16]), 30, &(States->score));
            CloseBlock(&(States->Blocks[17]), 30, &(States->score));
            break;
        case 24:
            CloseBlock(&(States->Blocks[4]), 80, &(States->score));
            CloseBlock(&(States->Blocks[6]), 80, &(States->score));
            CloseBlock(&(States->Blocks[7]), 80, &(States->score));
            CloseBlock(&(States->Blocks[12]), 50, &(States->score));
            CloseBlock(&(States->Blocks[14]), 30, &(States->score));
            CloseBlock(&(States->Blocks[18]), 30, &(States->score));
            break;
        case 25:
            CloseBlock(&(States->Blocks[4]), 20, &(States->score));
            CloseBlock(&(States->Blocks[6]), 30, &(States->score));
            CloseBlock(&(States->Blocks[7]), 30, &(States->score));
            CloseBlock(&(States->Blocks[11]), 30, &(States->score));
            CloseBlock(&(States->Blocks[12]), 30, &(States->score));
            CloseBlock(&(States->Blocks[14]), 20, &(States->score));
            break;
    }
    
    MakeHexagonMore(States -> Blocks, States -> size);
    MakeHexagonMore(States -> ChosenBlock, 3);

    return 0;
}

int IsMouseOnImagesG(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition SetCondition = {Position.x > 840, Position.x < 885, Position.y > 20, Position.y < 65};
    Condition moveCondition = {Position.x > 840, Position.x < 885, Position.y > 75, Position.y < 115};
    Condition S_setCondition = {Position.x >= 798, Position.x <= 898, Position.y >= 0, Position.y <= 200};
    Condition S_bagCondition = {Position.x >= 678, Position.x <= 898, Position.y >= 66, Position.y <= 126};

  
    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States->SettingsHold)) {
        DrawTexture(Images.settingsB, GetScreenWidth()/2 + 130, - 8, DARKGRAY);
        if(States -> BagHold == false) {DrawTexture(Images.bag, GetScreenWidth()/2 + 155, + 70, WHITE);}
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = true; States -> BagHold = false; PlaySound(clickS);}
        return 1;
    }
    if(moveCondition.a1 && moveCondition.a2 && moveCondition.a3 && moveCondition.a4 && !(States->SettingsHold) && !(States->BagHold)) {
        DrawTexture(Images.settingsB, GetScreenWidth()/2 + 130, - 8, WHITE); 
        DrawTexture(Images.bag, GetScreenWidth()/2 + 155, + 70, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            if(States -> BagHold == false) {States -> BagHold = true; PlaySound(clickS);}
            else {States -> BagHold = false;}
        }
        return 2;
    }
    if(S_setCondition.a1 && S_setCondition.a2 && S_setCondition.a3 && S_setCondition.a4 && States->SettingsHold) {
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = true; States -> BagHold = false;}
        return 3;
    }
    if(S_bagCondition.a1 && S_bagCondition.a2 && S_bagCondition.a3 && S_bagCondition.a4 && States->BagHold) {
        DrawTexture(Images.settingsB, GetScreenWidth()/2 + 130, - 8, WHITE);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> BagHold = true;}
        return 4;
    }
    
    if(States -> SettingsHold == false) {
        DrawTexture(Images.settingsB, GetScreenWidth()/2 + 130, - 8, WHITE); 
        if(States -> BagHold == false) {DrawTexture(Images.bag, GetScreenWidth()/2 + 155, + 70, WHITE);}
    }
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> BagHold = false; States -> selected = 0;}
    return 0;
}

int IsMouseOnSettingsG(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition ExitCondition = {Position.x > 828, Position.x < 868, Position.y > 20, Position.y < 60};
    Condition SoundOffCond = {Position.x > 828, Position.x < 868, Position.y > 80, Position.y < 120};
    Condition ResetCondition = {Position.x > 828, Position.x < 868, Position.y > 140, Position.y < 185};
   
    if(ExitCondition.a1 && ExitCondition.a2 && ExitCondition.a3 && ExitCondition.a4 && States->SettingsHold) {
        DrawTexture(Images.close, GetScreenWidth()/2 + 146 , + 20, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> exit = true; PlaySound(clickS);}
        return 1;
    }
    if(SoundOffCond.a1 && SoundOffCond.a2 && SoundOffCond.a3 && SoundOffCond.a4 && States->SettingsHold) {
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 146 , + 80, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            if(States -> Datas.IsSoundOff == false) {States -> Datas.IsSoundOff = true;}
            else {States -> Datas.IsSoundOff = false;}
            PlaySound(clickS);
        }
        return 2;
    }
    if(ResetCondition.a1 && ResetCondition.a2 && ResetCondition.a3 && ResetCondition.a4 && States->SettingsHold) {
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 146 , + 143, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {SetGameState(States, 1); SetEmptyData(&(States->Datas)); PlaySound(clickS);}
        return 3;
    }

    return 0; 
}

int IsMouseOnBagG(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition HCondition = {Position.x > 722, Position.x < 766, Position.y > 66, Position.y < 126};
    Condition PCondition = {Position.x > 766, Position.x < 810, Position.y > 66, Position.y < 126};
    Condition ZCondition = {Position.x > 810, Position.x < 854, Position.y > 66, Position.y < 126};
    Condition KCondition = {Position.x > 854, Position.x < 898, Position.y > 66, Position.y < 126};

    if(HCondition.a1 && HCondition.a2 && HCondition.a3 && HCondition.a4 && States->BagHold) {
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && States -> Datas.FeatureCount[0] != 0) {States -> selected = 1; PlaySound(clickS);}
        return 2;
    }
    if(PCondition.a1 && PCondition.a2 && PCondition.a3 && PCondition.a4 && States->BagHold) {
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && States -> Datas.FeatureCount[2] != 0) {States -> selected = 2; PlaySound(clickS);}
        return 3;
    }
    if(ZCondition.a1 && ZCondition.a2 && ZCondition.a3 && ZCondition.a4 && States->BagHold) {
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && States -> Datas.FeatureCount[3] != 0) {States -> selected = 3; PlaySound(clickS);}
        return 4;
    }
    if(KCondition.a1 && KCondition.a2 && KCondition.a3 && KCondition.a4 && States->BagHold) {
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && States -> Datas.FeatureCount[4] != 0) {States -> selected = 4; PlaySound(clickS);}
        return 5;
    }

    return 0;
}

int IsMouseOnImagesH(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 805, Position.x < 848, Position.y > 30, Position.y < 70};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition RiCondition = {Position.x > 815, Position.x < 848, Position.y > 270, Position.y < 310};
    Condition ShopCondition = {Position.x > 528, Position.x < 568, Position.y > 628, Position.y < 676};
    Condition LockCondition = {Position.x > 790, Position.x < 845, Position.y > 628, Position.y < 673};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsH, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameH, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(RiCondition.a1 && RiCondition.a2 && RiCondition.a3 && RiCondition.a4) {
        DrawTexture(Images.arrowh_R, GetScreenWidth()/2 + 70 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = POSEDION; States -> CurrentScreen = POSEDION; States -> Datas.voice = 1; PlaySound(clickS);}
        return 4;   
    } 
    if(ShopCondition.a1 && ShopCondition.a2 && ShopCondition.a3 && ShopCondition.a4) {
        DrawTexture(Images.shopH, GetScreenWidth()/2 - 196, 592, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = HADES; States -> CurrentScreen = SHOP; States -> Datas.voice = 1; PlaySound(clickS);}
        return 5;   
    } 
    if(LockCondition.a1 && LockCondition.a2 && LockCondition.a3 && LockCondition.a4) {
        DrawTexture(Images.lockedH, GetScreenWidth()/2 + 65, 580, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = HADES; States -> CurrentScreen = LEVELS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 6;   
    }

    if(States -> SettingsHold == false) {DrawTexture(Images.settingsH, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesP(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 810, Position.x < 860, Position.y > 30, Position.y < 80};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition LeCondition = {Position.x > 518, Position.x < 551, Position.y > 270, Position.y < 310};
    Condition RiCondition = {Position.x > 815, Position.x < 848, Position.y > 270, Position.y < 310};
    Condition ShopCondition = {Position.x > 528, Position.x < 568, Position.y > 628, Position.y < 676};
    Condition LockCondition = {Position.x > 790, Position.x < 845, Position.y > 628, Position.y < 673};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsP, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameP, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(LeCondition.a1 && LeCondition.a2 && LeCondition.a3 && LeCondition.a4) {
        DrawTexture(Images.arrowp_L, GetScreenWidth()/2  - 230 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = HADES; States -> CurrentScreen = HADES; States -> Datas.voice = 1; PlaySound(clickS);}
        return 3;   
    } 
    if(RiCondition.a1 && RiCondition.a2 && RiCondition.a3 && RiCondition.a4) {
        DrawTexture(Images.arrowp_R, GetScreenWidth()/2 + 70 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = DEMETER; States -> CurrentScreen = DEMETER; States -> Datas.voice = 1; PlaySound(clickS);}
        return 4;   
    } 
    if(ShopCondition.a1 && ShopCondition.a2 && ShopCondition.a3 && ShopCondition.a4) {
        DrawTexture(Images.shopP, GetScreenWidth()/2 - 196, 592, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = POSEDION; States -> CurrentScreen = SHOP; States -> Datas.voice = 1; PlaySound(clickS);}
        return 5;   
    } 
    if(LockCondition.a1 && LockCondition.a2 && LockCondition.a3 && LockCondition.a4) {
        DrawTexture(Images.lockedP, GetScreenWidth()/2 + 65, 580, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = POSEDION; States -> CurrentScreen = LEVELS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 6;   
    }

    if(States -> SettingsHold == false) {DrawTexture(Images.settingsP, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesD(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 805, Position.x < 860, Position.y > 30, Position.y < 80};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition LeCondition = {Position.x > 518, Position.x < 551, Position.y > 270, Position.y < 310};
    Condition RiCondition = {Position.x > 815, Position.x < 848, Position.y > 270, Position.y < 310};
    Condition ShopCondition = {Position.x > 528, Position.x < 568, Position.y > 628, Position.y < 676};
    Condition LockCondition = {Position.x > 790, Position.x < 845, Position.y > 628, Position.y < 673};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsD, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameD, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(LeCondition.a1 && LeCondition.a2 && LeCondition.a3 && LeCondition.a4) {
        DrawTexture(Images.arrowd_L, GetScreenWidth()/2  - 230 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = POSEDION; States -> CurrentScreen = POSEDION; States -> Datas.voice = 1; PlaySound(clickS);}
        return 3;   
    } 
    if(RiCondition.a1 && RiCondition.a2 && RiCondition.a3 && RiCondition.a4) {
        DrawTexture(Images.arrowd_R, GetScreenWidth()/2 + 70 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = ZEUS; States -> CurrentScreen = ZEUS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 4;   
    } 
    if(ShopCondition.a1 && ShopCondition.a2 && ShopCondition.a3 && ShopCondition.a4) {
        DrawTexture(Images.shopD, GetScreenWidth()/2 - 196, 592, DARKGRAY);
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = DEMETER; States -> CurrentScreen = SHOP; States -> Datas.voice = 1; PlaySound(clickS);}
        return 5;   
    } 
    if(LockCondition.a1 && LockCondition.a2 && LockCondition.a3 && LockCondition.a4) {
        DrawTexture(Images.lockedD, GetScreenWidth()/2 + 65, 580, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = DEMETER; States -> CurrentScreen = LEVELS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 6;   
    }

    if(States -> SettingsHold == false) {DrawTexture(Images.settingsD, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesZ(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 805, Position.x < 848, Position.y > 30, Position.y < 70};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition LeCondition = {Position.x > 518, Position.x < 551, Position.y > 270, Position.y < 310};
    Condition RiCondition = {Position.x > 815, Position.x < 848, Position.y > 270, Position.y < 310};
    Condition ShopCondition = {Position.x > 528, Position.x < 568, Position.y > 628, Position.y < 676};
    Condition LockCondition = {Position.x > 790, Position.x < 845, Position.y > 628, Position.y < 673};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsB, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameZ, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(LeCondition.a1 && LeCondition.a2 && LeCondition.a3 && LeCondition.a4) {
        DrawTexture(Images.arrowz_L, GetScreenWidth()/2  - 230 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = DEMETER; States -> CurrentScreen = DEMETER; States -> Datas.voice = 1; PlaySound(clickS);}
        return 3;   
    } 
    if(RiCondition.a1 && RiCondition.a2 && RiCondition.a3 && RiCondition.a4) {
        DrawTexture(Images.arrowz_R, GetScreenWidth()/2 + 70 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = KRONOS; States -> CurrentScreen = KRONOS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 4;   
    } 
    if(ShopCondition.a1 && ShopCondition.a2 && ShopCondition.a3 && ShopCondition.a4) {
        DrawTexture(Images.shopZ, GetScreenWidth()/2 - 196, 592, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = ZEUS; States -> CurrentScreen = SHOP; States -> Datas.voice = 1; PlaySound(clickS);}
        return 5;   
    } 
    if(LockCondition.a1 && LockCondition.a2 && LockCondition.a3 && LockCondition.a4) {
        DrawTexture(Images.lockedZ, GetScreenWidth()/2 + 65, 580, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = ZEUS; States -> CurrentScreen = LEVELS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 6;   
    }

    if(States -> SettingsHold == false) {DrawTexture(Images.settingsB, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesK(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 805, Position.x < 848, Position.y > 30, Position.y < 70};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition LeCondition = {Position.x > 518, Position.x < 551, Position.y > 270, Position.y < 310};
    Condition RiCondition = {Position.x > 815, Position.x < 848, Position.y > 270, Position.y < 310};
    Condition ShopCondition = {Position.x > 528, Position.x < 568, Position.y > 628, Position.y < 676};
    Condition LockCondition = {Position.x > 790, Position.x < 845, Position.y > 628, Position.y < 673};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsK, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(LeCondition.a1 && LeCondition.a2 && LeCondition.a3 && LeCondition.a4) {
        DrawTexture(Images.arrowk_L, GetScreenWidth()/2  - 230 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = ZEUS; States -> CurrentScreen = ZEUS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 3;   
    } 
    if(RiCondition.a1 && RiCondition.a2 && RiCondition.a3 && RiCondition.a4) {
        DrawTexture(Images.arrowk_R, GetScreenWidth()/2 + 70 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = BOSS; States -> CurrentScreen = BOSS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 4;   
    } 
    if(ShopCondition.a1 && ShopCondition.a2 && ShopCondition.a3 && ShopCondition.a4) {
        DrawTexture(Images.shopK, GetScreenWidth()/2 - 196, 592, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = KRONOS; States -> CurrentScreen = SHOP; States -> Datas.voice = 1; PlaySound(clickS);}
        return 5;   
    } 
    if(LockCondition.a1 && LockCondition.a2 && LockCondition.a3 && LockCondition.a4) {
        DrawTexture(Images.lockedK, GetScreenWidth()/2 + 65, 580, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = KRONOS; States -> CurrentScreen = LEVELS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 6;   
    }

    if(States -> SettingsHold == false) {DrawTexture(Images.settingsK, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesB(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();
    
    Condition SetCondition = {Position.x > 805, Position.x < 848, Position.y > 30, Position.y < 70};
    Condition FraCondition = {Position.x > 518, Position.x < 585, Position.y > 25, Position.y < 85};
    Condition LeCondition = {Position.x > 518, Position.x < 551, Position.y > 270, Position.y < 310};
    Condition PlayCondition = {Position.x > 602, Position.x < 762, Position.y > 106, Position.y < 248};

    if(SetCondition.a1 && SetCondition.a2 && SetCondition.a3 && SetCondition.a4 && !(States -> SettingsHold)) {
        DrawTexture(Images.settingsK, GetScreenWidth()/2 + 95, 0, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = true; States -> ProfilHold = false; PlaySound(clickS);}
        return 1;
    }
    if(FraCondition.a1 && FraCondition.a2 && FraCondition.a3 && FraCondition.a4 && !(States -> ProfilHold)) {
        DrawTexture(Images.frameK, GetScreenWidth()/2 - 180, +5, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = true; PlaySound(clickS);}
        return 2;
    }
    if(LeCondition.a1 && LeCondition.a2 && LeCondition.a3 && LeCondition.a4) {
        DrawTexture(Images.arrowk_L, GetScreenWidth()/2  - 230 , + 240, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> SettingsHold = false; States -> ProfilHold = false; States -> PerviousScreen = KRONOS; States -> CurrentScreen = KRONOS; States -> Datas.voice = 1; PlaySound(clickS);}
        return 3;   
    }
    if(PlayCondition.a1 && PlayCondition.a2 && PlayCondition.a3 && PlayCondition.a4) {
        DrawTexture(Images.playB, GetScreenWidth()/2 - 100, - 20, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && States -> Datas.Locks[25]) {
            States -> SettingsHold = false;
            States -> ProfilHold = false;
            SetGameState(States, 26);
            States -> PerviousScreen = BOSS;
            States -> CurrentScreen = GAMEPLAY;
            PlaySound(clickS);
        }
    }
    
    if(States -> SettingsHold == false) {DrawTexture(Images.settingsB, GetScreenWidth()/2 + 95, 0, WHITE);}
    if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> SettingsHold = false; States -> ProfilHold = false;}
    
    return 0;
}

int IsMouseOnImagesL(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition Conditions[26];
    Condition ArrowCond = {Position.x > 342, Position.x < 449, Position.y > 604, Position.y < 704};

    for(int i=0; i<25; i++) {
        Conditions[i].a1 = Position.x > (342 + (i%5)*144);
        Conditions[i].a2 = Position.x < (449 + (i%5)*144);
        Conditions[i].a3 = Position.y > (34 + ((int) i/5)*114);
        Conditions[i].a4 = Position.y < (134 + ((int) i/5)*114);
    }

    Conditions[25] = {Position.x > (342 + (27%5)*144), Position.x < (449 + (27%5)*144), Position.y > (34 + ((int) 27/5)*114), Position.y < (134 + ((int) 27/5)*114)};

    for(int i=0; i<25; i++) {
        if(Conditions[i].a1 && Conditions[i].a2 && Conditions[i].a3 && Conditions[i].a4 && States -> Datas.Locks[i]) {
            DrawRectangleLinesEx((Rectangle) { (float) (342 + (i%5)*144), (float) (34 + ((int) i/5)*114), 107, 100 }, 2.0, GOLD);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ( States -> Datas.FeatureCount[1] > 0 || States -> Datas.Locks[i+1] || i == 0)) {
                Screen tempSec = States -> PerviousScreen;
                SetGameState(States, i+1);
                States -> CurrentScreen = GAMEPLAY;
                States -> PerviousScreen = tempSec;
                PlaySound(clickS);
            }
            return 1;
        }
    }

    if(Conditions[25].a1 && Conditions[25].a2 && Conditions[25].a3 && Conditions[25].a4 && States -> Datas.Locks[25]) {
        DrawRectangleLinesEx((Rectangle) { 342 + (27%5)*144, 34 + ((int) 27/5)*114, 107, 100 }, 2.0, GOLD);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            States -> CurrentScreen = BOSS;
            States -> PerviousScreen = BOSS;
            PlaySound(clickS);
        }
        return 2;
    }

    if(ArrowCond.a1 && ArrowCond.a2 && ArrowCond.a3 && ArrowCond.a4) {
        DrawRectangleLinesEx((Rectangle) { 342, 604, 107, 100 }, 2.0, GOLD);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            States -> CurrentScreen = States -> PerviousScreen;
            PlaySound(clickS);
        }
    }

    return 0;
}

int IsMouseOnImagesS(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition ArCondition = {Position.x > 352, Position.x <  433, Position.y > 12, Position.y < 95};
    Condition FeatureH = {Position.x > 893, Position.x <  983, Position.y > 157, Position.y < 202};
    Condition FeatureD = {Position.x > 893, Position.x <  983, Position.y > 275, Position.y < 320};
    Condition FeatureP = {Position.x > 893, Position.x <  983, Position.y > 393, Position.y < 438};
    Condition FeatureZ = {Position.x > 893, Position.x <  983, Position.y > 511, Position.y < 556};
    Condition FeatureK = {Position.x > 893, Position.x <  983, Position.y > 629, Position.y < 674};

    if(ArCondition.a1 && ArCondition.a2 && ArCondition.a3 && ArCondition.a4) {
        DrawTexture(Images.arrowS, GetScreenWidth()/2 - 540, - 165, DARKGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {States -> CurrentScreen = States -> PerviousScreen; PlaySound(clickS);}
    }
    if(FeatureH.a1 && FeatureH.a2 && FeatureH.a3 && FeatureH.a4) {
        DrawText("250$", 918, 180, 20, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && States -> Datas.coin > 250 && States -> Datas.FeatureCount[0] < 99) {
            States -> Datas.FeatureCount[0] += 1;
            States -> Datas.coin -= 250;
            PlaySound(clickS);
        }
    }
    if(FeatureD.a1 && FeatureD.a2 && FeatureD.a3 && FeatureD.a4) {
        DrawText("300$", 918, 298, 20, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && States -> Datas.coin > 300 && States -> Datas.FeatureCount[1] < 5) {
            States -> Datas.FeatureCount[1] += 1;
            States -> Datas.coin -= 300;
            PlaySound(clickS);
        }
    }
    if(FeatureP.a1 && FeatureP.a2 && FeatureP.a3 && FeatureP.a4) {
        DrawText("350$", 918, 416, 20, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && States -> Datas.coin > 350 && States -> Datas.FeatureCount[2] < 99) {
            States -> Datas.FeatureCount[2] += 1;
            States -> Datas.coin -= 350;
            PlaySound(clickS);
        }
    }
    if(FeatureZ.a1 && FeatureZ.a2 && FeatureZ.a3 && FeatureZ.a4) {
        DrawText("400$", 918, 534, 20, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && States -> Datas.coin > 400 && States -> Datas.FeatureCount[3] < 99) {
            States -> Datas.FeatureCount[3] += 1;
            States -> Datas.coin -= 400;
            PlaySound(clickS);
        }
    }
    if(FeatureK.a1 && FeatureK.a2 && FeatureK.a3 && FeatureK.a4) {
        DrawText("450$", 918, 652, 20, BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && States -> Datas.coin > 450 && States -> Datas.FeatureCount[4] < 99) {
            States -> Datas.FeatureCount[4] += 1;
            States -> Datas.coin -= 450;
            PlaySound(clickS);
        }
    }
    
    return 0;
}

int IsMouseOnSettings(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition ExitCondition = {Position.x > 800, Position.x < 842, Position.y > 23, Position.y < 60};
    Condition SoundOffCond = {Position.x > 800, Position.x < 842, Position.y > 83, Position.y < 120};
    Condition ResetCondition = {Position.x > 800, Position.x < 842, Position.y > 143, Position.y < 185};
   
    if(ExitCondition.a1 && ExitCondition.a2 && ExitCondition.a3 && ExitCondition.a4 && States->SettingsHold) {
        DrawTexture(Images.close, GetScreenWidth()/2 + 120 , + 23, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> exit = true; PlaySound(clickS);}
        return 1;
    }
    if(SoundOffCond.a1 && SoundOffCond.a2 && SoundOffCond.a3 && SoundOffCond.a4 && States->SettingsHold) {
        DrawTexture(Images.soundOff, GetScreenWidth()/2 + 120 , + 83, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            if(States -> Datas.IsSoundOff == false) {States -> Datas.IsSoundOff = true;}
            else {States -> Datas.IsSoundOff = false;}
            PlaySound(clickS);
        }
        return 2;
    }
    if(ResetCondition.a1 && ResetCondition.a2 && ResetCondition.a3 && ResetCondition.a4 && States->SettingsHold) {
        DrawTexture(Images.deleteA, GetScreenWidth()/2 + 120 , + 143, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {SetGameState(States, 1); SetEmptyData(&(States->Datas)); PlaySound(clickS);}
        return 3;
    }

    return 0; 
}

int IsMouseOnProfil(GameState *States, AllImages Images, Sound clickS) {
    Vector2 Position = GetMousePosition();

    Condition HCondition = {Position.x > GetScreenWidth()/2 - 165, Position.x < GetScreenWidth()/2 - 115, Position.y > 15, Position.y < 75};
    Condition PCondition = {Position.x > GetScreenWidth()/2 - 80, Position.x < GetScreenWidth()/2 - 30, Position.y > 15, Position.y < 75};
    Condition DCondition = {Position.x > GetScreenWidth()/2 - 165, Position.x < GetScreenWidth()/2 - 115, Position.y > 90, Position.y < 150};
    Condition ZCondition = {Position.x > GetScreenWidth()/2 - 80, Position.x < GetScreenWidth()/2 - 20, Position.y > 90, Position.y < 150};
    Condition KCondition = {Position.x > GetScreenWidth()/2 - 165, Position.x < GetScreenWidth()/2 - 105, Position.y > 165, Position.y < 225};
    Condition BCondition = {Position.x > GetScreenWidth()/2 - 80, Position.x < GetScreenWidth()/2 - 30, Position.y > 165, Position.y < 225};

    if(HCondition.a1 && HCondition.a2 && HCondition.a3 && HCondition.a4) {
        DrawTexture(Images.profileH, GetScreenWidth()/2 - 165 , + 15, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 1; States -> ProfilHold = true;}
        return 1;
    }
    if(PCondition.a1 && PCondition.a2 && PCondition.a3 && PCondition.a4 && IsFinished(*States, 0) == 5) {
        DrawTexture(Images.profileP, GetScreenWidth()/2 - 80 , + 15, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 2; States -> ProfilHold = false;}
        return 2;
    }
    if(DCondition.a1 && DCondition.a2 && DCondition.a3 && DCondition.a4 && IsFinished(*States, 1) == 5) {
        DrawTexture(Images.profileD, GetScreenWidth()/2 - 165 , + 90, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 3; States -> ProfilHold = false;}
        return 3;
    }
    if(ZCondition.a1 && ZCondition.a2 && ZCondition.a3 && ZCondition.a4 && IsFinished(*States, 2) == 5) {
        DrawTexture(Images.profileZ, GetScreenWidth()/2 - 80 , + 90, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 4; States -> ProfilHold = false;}
        return 4;
    }
    if(KCondition.a1 && KCondition.a2 && KCondition.a3 && KCondition.a4 && IsFinished(*States, 3) == 5) {
        DrawTexture(Images.profileK, GetScreenWidth()/2 - 165 , + 165, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 5; States -> ProfilHold = false;}
        return 5;
    }
    if(BCondition.a1 && BCondition.a2 && BCondition.a3 && BCondition.a4 && IsFinished(*States, 4) == 5) {
        DrawTexture(Images.profileB, GetScreenWidth()/2 - 80 , + 165, DARKGRAY);
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {States -> Datas.picture = 6; States -> ProfilHold = false;}
        return 6;
    }
    return 0;
}

int LoadAllImages(AllImages *Images) {
    Images -> arrowB = LoadTexture("C:\\HexaSort2\\resources\\arrowB.png");
    Images -> arrowd_L = LoadTexture("C:\\HexaSort2\\resources\\arrowd_L.png");
    Images -> arrowd_R = LoadTexture("C:\\HexaSort2\\resources\\arrowd_R.png");
    Images -> arrowh_R = LoadTexture("C:\\HexaSort2\\resources\\arrowh_R.png");
    Images -> arrowk_L = LoadTexture("C:\\HexaSort2\\resources\\arrowk_L.png");
    Images -> arrowk_R = LoadTexture("C:\\HexaSort2\\resources\\arrowk_R.png");
    Images -> ArrowL = LoadTexture("C:\\HexaSort2\\resources\\ArrowL.png");
    Images -> arrowp_L = LoadTexture("C:\\HexaSort2\\resources\\arrowp_L.png");
    Images -> arrowp_R = LoadTexture("C:\\HexaSort2\\resources\\arrowp_R.png");
    Images -> arrowS = LoadTexture("C:\\HexaSort2\\resources\\arrowS.png");
    Images -> arrowz_L = LoadTexture("C:\\HexaSort2\\resources\\arrowz_L.png");
    Images -> arrowz_R = LoadTexture("C:\\HexaSort2\\resources\\arrowz_R.png");
    Images -> background = LoadTexture("C:\\HexaSort2\\resources\\background.png");
    Images -> bag = LoadTexture("C:\\HexaSort2\\resources\\bag.png");
    Images -> bronze = LoadTexture("C:\\HexaSort2\\resources\\bronze.png");
    Images -> bronzeG = LoadTexture("C:\\HexaSort2\\resources\\bronzeG.png");
    Images -> close = LoadTexture("C:\\HexaSort2\\resources\\close.png");
    Images -> coin = LoadTexture("C:\\HexaSort2\\resources\\coin.png");
    Images -> coincounterB = LoadTexture("C:\\HexaSort2\\resources\\coincounterB.png");
    Images -> coinG = LoadTexture("C:\\HexaSort2\\resources\\coinG.png");
    Images -> counterD = LoadTexture("C:\\HexaSort2\\resources\\counterD.png");
    Images -> counterH = LoadTexture("C:\\HexaSort2\\resources\\counterH.png");
    Images -> counterK = LoadTexture("C:\\HexaSort2\\resources\\counterK.png");
    Images -> counterP = LoadTexture("C:\\HexaSort2\\resources\\counterP.png");
    Images -> counterZ = LoadTexture("C:\\HexaSort2\\resources\\counterZ.png");
    Images -> cup = LoadTexture("C:\\HexaSort2\\resources\\cup.png");
    Images -> deleteA = LoadTexture("C:\\HexaSort2\\resources\\deleteA.png");
    Images -> demeter0 = LoadTexture("C:\\HexaSort2\\resources\\demeter0.png");
    Images -> demeter1 = LoadTexture("C:\\HexaSort2\\resources\\demeter1.png");
    Images -> demeter2 = LoadTexture("C:\\HexaSort2\\resources\\demeter2.png");
    Images -> demeter3 = LoadTexture("C:\\HexaSort2\\resources\\demeter3.png");
    Images -> demeter4 = LoadTexture("C:\\HexaSort2\\resources\\demeter4.png");
    Images -> demeter5 = LoadTexture("C:\\HexaSort2\\resources\\demeter5.png");
    Images -> diamond = LoadTexture("C:\\HexaSort2\\resources\\diamond.png");
    Images -> diamondG = LoadTexture("C:\\HexaSort2\\resources\\diamondG.png");
    Images -> downD = LoadTexture("C:\\HexaSort2\\resources\\downD.png");
    Images -> downH = LoadTexture("C:\\HexaSort2\\resources\\downH.png");
    Images -> downK = LoadTexture("C:\\HexaSort2\\resources\\downK.png");
    Images -> downP = LoadTexture("C:\\HexaSort2\\resources\\downP.png");
    Images -> downZ = LoadTexture("C:\\HexaSort2\\resources\\downZ.png");
    Images -> featureD = LoadTexture("C:\\HexaSort2\\resources\\featureD.png");
    Images -> featureH = LoadTexture("C:\\HexaSort2\\resources\\featureH.png");
    Images -> featureK = LoadTexture("C:\\HexaSort2\\resources\\featureK.png");
    Images -> featureP = LoadTexture("C:\\HexaSort2\\resources\\featureP.png");
    Images -> featureZ = LoadTexture("C:\\HexaSort2\\resources\\featureZ.png");
    Images -> frameB = LoadTexture("C:\\HexaSort2\\resources\\frameB.png");
    Images -> frameD = LoadTexture("C:\\HexaSort2\\resources\\frameD.png");
    Images -> frameH = LoadTexture("C:\\HexaSort2\\resources\\frameH.png");
    Images -> frameK = LoadTexture("C:\\HexaSort2\\resources\\frameK.png");
    Images -> frameP = LoadTexture("C:\\HexaSort2\\resources\\frameP.png");
    Images -> frameZ = LoadTexture("C:\\HexaSort2\\resources\\frameZ.png");
    Images -> go = LoadTexture("C:\\HexaSort2\\resources\\go.png");
    Images -> gold = LoadTexture("C:\\HexaSort2\\resources\\gold.png");
    Images -> goldG = LoadTexture("C:\\HexaSort2\\resources\\goldG.png");
    Images -> groundB = LoadTexture("C:\\HexaSort2\\resources\\groundB.png");
    Images -> groundD = LoadTexture("C:\\HexaSort2\\resources\\groundD.png");
    Images -> groundG = LoadTexture("C:\\HexaSort2\\resources\\groundG.png");
    Images -> groundG2 = LoadTexture("C:\\HexaSort2\\resources\\groundG2.png");
    Images -> groundH = LoadTexture("C:\\HexaSort2\\resources\\groundH.png");
    Images -> groundK = LoadTexture("C:\\HexaSort2\\resources\\groundK.png");
    Images -> groundL = LoadTexture("C:\\HexaSort2\\resources\\groundL.png");
    Images -> groundP = LoadTexture("C:\\HexaSort2\\resources\\groundP.png");
    Images -> groundS = LoadTexture("C:\\HexaSort2\\resources\\groundS.png");
    Images -> groundZ = LoadTexture("C:\\HexaSort2\\resources\\groundZ.png");
    Images -> hades0 = LoadTexture("C:\\HexaSort2\\resources\\hades0.png");
    Images -> hades1 = LoadTexture("C:\\HexaSort2\\resources\\hades1.png");
    Images -> hades2 = LoadTexture("C:\\HexaSort2\\resources\\hades2.png");
    Images -> hades3 = LoadTexture("C:\\HexaSort2\\resources\\hades3.png");
    Images -> hades4 = LoadTexture("C:\\HexaSort2\\resources\\hades4.png");
    Images -> hades5 = LoadTexture("C:\\HexaSort2\\resources\\hades5.png");
    Images -> heart = LoadTexture("C:\\HexaSort2\\resources\\heart.png");
    Images -> homeD = LoadTexture("C:\\HexaSort2\\resources\\homeD.png");
    Images -> homeH = LoadTexture("C:\\HexaSort2\\resources\\homeH.png");
    Images -> homeK = LoadTexture("C:\\HexaSort2\\resources\\homeK.png");
    Images -> homeP = LoadTexture("C:\\HexaSort2\\resources\\homeP.png");
    Images -> homeZ = LoadTexture("C:\\HexaSort2\\resources\\homeZ.png");
    Images -> kronos0 = LoadTexture("C:\\HexaSort2\\resources\\kronos0.png");
    Images -> kronos1 = LoadTexture("C:\\HexaSort2\\resources\\kronos1.png");
    Images -> kronos2 = LoadTexture("C:\\HexaSort2\\resources\\kronos2.png");
    Images -> kronos3 = LoadTexture("C:\\HexaSort2\\resources\\kronos3.png");
    Images -> kronos4 = LoadTexture("C:\\HexaSort2\\resources\\kronos4.png");
    Images -> kronos5 = LoadTexture("C:\\HexaSort2\\resources\\kronos5.png");
    Images -> L1 = LoadTexture("C:\\HexaSort2\\resources\\L1.png");
    Images -> L2 = LoadTexture("C:\\HexaSort2\\resources\\L2.png");
    Images -> L3 = LoadTexture("C:\\HexaSort2\\resources\\L3.png");
    Images -> L4 = LoadTexture("C:\\HexaSort2\\resources\\L4.png");
    Images -> L5 = LoadTexture("C:\\HexaSort2\\resources\\L5.png");
    Images -> L6 = LoadTexture("C:\\HexaSort2\\resources\\L6.png");
    Images -> L7 = LoadTexture("C:\\HexaSort2\\resources\\L7.png");
    Images -> L8 = LoadTexture("C:\\HexaSort2\\resources\\L8.png");
    Images -> L9 = LoadTexture("C:\\HexaSort2\\resources\\L9.png");
    Images -> L10 = LoadTexture("C:\\HexaSort2\\resources\\L10.png");
    Images -> L11 = LoadTexture("C:\\HexaSort2\\resources\\L11.png");
    Images -> L12 = LoadTexture("C:\\HexaSort2\\resources\\L12.png");
    Images -> L13 = LoadTexture("C:\\HexaSort2\\resources\\L13.png");
    Images -> L14 = LoadTexture("C:\\HexaSort2\\resources\\L14.png");
    Images -> L15 = LoadTexture("C:\\HexaSort2\\resources\\L15.png");
    Images -> L16 = LoadTexture("C:\\HexaSort2\\resources\\L16.png");
    Images -> L17 = LoadTexture("C:\\HexaSort2\\resources\\L17.png");
    Images -> L18 = LoadTexture("C:\\HexaSort2\\resources\\L18.png");
    Images -> L19 = LoadTexture("C:\\HexaSort2\\resources\\L19.png");
    Images -> L20 = LoadTexture("C:\\HexaSort2\\resources\\L20.png");
    Images -> L21 = LoadTexture("C:\\HexaSort2\\resources\\L21.png");
    Images -> L22 = LoadTexture("C:\\HexaSort2\\resources\\L22.png");
    Images -> L23 = LoadTexture("C:\\HexaSort2\\resources\\L23.png");
    Images -> L24 = LoadTexture("C:\\HexaSort2\\resources\\L24.png");
    Images -> L25 = LoadTexture("C:\\HexaSort2\\resources\\L25.png");
    Images -> L26 = LoadTexture("C:\\HexaSort2\\resources\\L26.png");
    Images -> lockedD = LoadTexture("C:\\HexaSort2\\resources\\lockedD.png");
    Images -> lockedH = LoadTexture("C:\\HexaSort2\\resources\\lockedH.png");
    Images -> lockedK = LoadTexture("C:\\HexaSort2\\resources\\lockedK.png");
    Images -> lockedP = LoadTexture("C:\\HexaSort2\\resources\\lockedP.png");
    Images -> lockedZ = LoadTexture("C:\\HexaSort2\\resources\\lockedZ.png");
    Images -> move = LoadTexture("C:\\HexaSort2\\resources\\move.png");
    Images -> move2 = LoadTexture("C:\\HexaSort2\\resources\\move2.png");
    Images -> playB = LoadTexture("C:\\HexaSort2\\resources\\playB.png");
    Images -> poseidon0 = LoadTexture("C:\\HexaSort2\\resources\\poseidon0.png");
    Images -> poseidon1 = LoadTexture("C:\\HexaSort2\\resources\\poseidon1.png");
    Images -> poseidon2 = LoadTexture("C:\\HexaSort2\\resources\\poseidon2.png");
    Images -> poseidon3 = LoadTexture("C:\\HexaSort2\\resources\\poseidon3.png");
    Images -> poseidon4 = LoadTexture("C:\\HexaSort2\\resources\\poseidon4.png");
    Images -> poseidon5 = LoadTexture("C:\\HexaSort2\\resources\\poseidon5.png");
    Images -> profileB = LoadTexture("C:\\HexaSort2\\resources\\profileB.png");
    Images -> ProfileB2 = LoadTexture("C:\\HexaSort2\\resources\\ProfileB2.png");
    Images -> profileD = LoadTexture("C:\\HexaSort2\\resources\\profileD.png");
    Images -> profileD2 = LoadTexture("C:\\HexaSort2\\resources\\profileD2.png");
    Images -> profileH = LoadTexture("C:\\HexaSort2\\resources\\profileH.png");
    Images -> profileH2 = LoadTexture("C:\\HexaSort2\\resources\\profileH2.png");
    Images -> profileK = LoadTexture("C:\\HexaSort2\\resources\\profileK.png");
    Images -> profileK2 = LoadTexture("C:\\HexaSort2\\resources\\profileK2.png");
    Images -> profileP = LoadTexture("C:\\HexaSort2\\resources\\profileP.png");
    Images -> profileP2 = LoadTexture("C:\\HexaSort2\\resources\\profileP2.png");
    Images -> profileZ = LoadTexture("C:\\HexaSort2\\resources\\profileZ.png");
    Images -> profileZ2 = LoadTexture("C:\\HexaSort2\\resources\\profileZ2.png");
    Images -> settingsB = LoadTexture("C:\\HexaSort2\\resources\\settingsB.png");
    Images -> settingsD = LoadTexture("C:\\HexaSort2\\resources\\settingsD.png");
    Images -> settingsG = LoadTexture("C:\\HexaSort2\\resources\\settingsG.png");
    Images -> settingsH = LoadTexture("C:\\HexaSort2\\resources\\settingsH.png");
    Images -> settingsK = LoadTexture("C:\\HexaSort2\\resources\\settingsK.png");
    Images -> settingsP = LoadTexture("C:\\HexaSort2\\resources\\settingsP.png");
    Images -> settingsS = LoadTexture("C:\\HexaSort2\\resources\\settingsS.png");
    Images -> settingsZ = LoadTexture("C:\\HexaSort2\\resources\\settingsZ.png");
    Images -> shopD = LoadTexture("C:\\HexaSort2\\resources\\shopD.png");
    Images -> shopH = LoadTexture("C:\\HexaSort2\\resources\\shopH.png");
    Images -> shopK = LoadTexture("C:\\HexaSort2\\resources\\shopK.png");
    Images -> shopP = LoadTexture("C:\\HexaSort2\\resources\\shopP.png");
    Images -> shopZ = LoadTexture("C:\\HexaSort2\\resources\\shopZ.png");
    Images -> soundOff = LoadTexture("C:\\HexaSort2\\resources\\soundOff.png");
    Images -> starD = LoadTexture("C:\\HexaSort2\\resources\\starD.png");
    Images -> starH = LoadTexture("C:\\HexaSort2\\resources\\starH.png");
    Images -> starK = LoadTexture("C:\\HexaSort2\\resources\\starK.png");
    Images -> starP = LoadTexture("C:\\HexaSort2\\resources\\starP.png");
    Images -> starZ = LoadTexture("C:\\HexaSort2\\resources\\starZ.png");
    Images -> textD = LoadTexture("C:\\HexaSort2\\resources\\textD.png");
    Images -> textH = LoadTexture("C:\\HexaSort2\\resources\\textH.png");
    Images -> textK = LoadTexture("C:\\HexaSort2\\resources\\textK.png");
    Images -> textP = LoadTexture("C:\\HexaSort2\\resources\\textP.png");
    Images -> textZ = LoadTexture("C:\\HexaSort2\\resources\\textZ.png");
    Images -> timer = LoadTexture("C:\\HexaSort2\\resources\\timer.png");
    Images -> timer2 = LoadTexture("C:\\HexaSort2\\resources\\timer2.png");
    Images -> zeus0 = LoadTexture("C:\\HexaSort2\\resources\\zeus0.png");
    Images -> zeus1 = LoadTexture("C:\\HexaSort2\\resources\\zeus1.png");
    Images -> zeus2 = LoadTexture("C:\\HexaSort2\\resources\\zeus2.png");
    Images -> zeus3 = LoadTexture("C:\\HexaSort2\\resources\\zeus3.png");
    Images -> zeus4 = LoadTexture("C:\\HexaSort2\\resources\\zeus4.png");
    Images -> zeus5 = LoadTexture("C:\\HexaSort2\\resources\\zeus5.png");

    return 0;
}

int UnloadAllImages(AllImages *Images) {
    UnloadTexture(Images -> arrowB);
    UnloadTexture(Images -> arrowd_L);
    UnloadTexture(Images -> arrowd_R);
    UnloadTexture(Images -> arrowh_R);
    UnloadTexture(Images -> arrowk_L);
    UnloadTexture(Images -> arrowk_R);
    UnloadTexture(Images -> ArrowL);
    UnloadTexture(Images -> arrowp_L);
    UnloadTexture(Images -> arrowp_R);
    UnloadTexture(Images -> arrowS);
    UnloadTexture(Images -> arrowz_L);
    UnloadTexture(Images -> arrowz_R);
    UnloadTexture(Images -> background);
    UnloadTexture(Images -> bag);
    UnloadTexture(Images -> bronze);
    UnloadTexture(Images -> bronzeG);
    UnloadTexture(Images -> close);
    UnloadTexture(Images -> coin);
    UnloadTexture(Images -> coincounterB);
    UnloadTexture(Images -> coinG);
    UnloadTexture(Images -> counterD);
    UnloadTexture(Images -> counterH);
    UnloadTexture(Images -> counterK);
    UnloadTexture(Images -> counterP);
    UnloadTexture(Images -> counterZ);
    UnloadTexture(Images -> cup);
    UnloadTexture(Images -> deleteA);
    UnloadTexture(Images -> demeter0);
    UnloadTexture(Images -> demeter1);
    UnloadTexture(Images -> demeter2);
    UnloadTexture(Images -> demeter3);
    UnloadTexture(Images -> demeter4);
    UnloadTexture(Images -> demeter5);
    UnloadTexture(Images -> diamond);
    UnloadTexture(Images -> diamondG);
    UnloadTexture(Images -> downD);
    UnloadTexture(Images -> downH);
    UnloadTexture(Images -> downK);
    UnloadTexture(Images -> downP);
    UnloadTexture(Images -> downZ);
    UnloadTexture(Images -> featureD);
    UnloadTexture(Images -> featureH);
    UnloadTexture(Images -> featureK);
    UnloadTexture(Images -> featureP);
    UnloadTexture(Images -> featureZ);
    UnloadTexture(Images -> frameB);
    UnloadTexture(Images -> frameD);
    UnloadTexture(Images -> frameH);
    UnloadTexture(Images -> frameK);
    UnloadTexture(Images -> frameP);
    UnloadTexture(Images -> frameZ);
    UnloadTexture(Images -> go);
    UnloadTexture(Images -> gold);
    UnloadTexture(Images -> goldG);
    UnloadTexture(Images -> groundB);
    UnloadTexture(Images -> groundD);
    UnloadTexture(Images -> groundG);
    UnloadTexture(Images -> groundG2);
    UnloadTexture(Images -> groundH);
    UnloadTexture(Images -> groundK);
    UnloadTexture(Images -> groundL);
    UnloadTexture(Images -> groundP);
    UnloadTexture(Images -> groundS);
    UnloadTexture(Images -> groundZ);
    UnloadTexture(Images -> hades0);
    UnloadTexture(Images -> hades1);
    UnloadTexture(Images -> hades2);
    UnloadTexture(Images -> hades3);
    UnloadTexture(Images -> hades4);
    UnloadTexture(Images -> hades5);
    UnloadTexture(Images -> heart);
    UnloadTexture(Images -> homeD);
    UnloadTexture(Images -> homeH);
    UnloadTexture(Images -> homeK);
    UnloadTexture(Images -> homeP);
    UnloadTexture(Images -> homeZ);
    UnloadTexture(Images -> kronos0);
    UnloadTexture(Images -> kronos1);
    UnloadTexture(Images -> kronos2);
    UnloadTexture(Images -> kronos3);
    UnloadTexture(Images -> kronos4);
    UnloadTexture(Images -> kronos5);
    UnloadTexture(Images -> L1);
    UnloadTexture(Images -> L2);
    UnloadTexture(Images -> L3);
    UnloadTexture(Images -> L4);
    UnloadTexture(Images -> L5);
    UnloadTexture(Images -> L6);
    UnloadTexture(Images -> L7);
    UnloadTexture(Images -> L8);
    UnloadTexture(Images -> L9);
    UnloadTexture(Images -> L10);
    UnloadTexture(Images -> L11);
    UnloadTexture(Images -> L12);
    UnloadTexture(Images -> L13);
    UnloadTexture(Images -> L14);
    UnloadTexture(Images -> L15);
    UnloadTexture(Images -> L16);
    UnloadTexture(Images -> L17);
    UnloadTexture(Images -> L18);
    UnloadTexture(Images -> L19);
    UnloadTexture(Images -> L20);
    UnloadTexture(Images -> L21);
    UnloadTexture(Images -> L22);
    UnloadTexture(Images -> L23);
    UnloadTexture(Images -> L24);
    UnloadTexture(Images -> L25);
    UnloadTexture(Images -> L26);
    UnloadTexture(Images -> lockedD);
    UnloadTexture(Images -> lockedH);
    UnloadTexture(Images -> lockedK);
    UnloadTexture(Images -> lockedP);
    UnloadTexture(Images -> lockedZ);
    UnloadTexture(Images -> move);
    UnloadTexture(Images -> move2);
    UnloadTexture(Images -> playB);
    UnloadTexture(Images -> poseidon0);
    UnloadTexture(Images -> poseidon1);
    UnloadTexture(Images -> poseidon2);
    UnloadTexture(Images -> poseidon3);
    UnloadTexture(Images -> poseidon4);
    UnloadTexture(Images -> poseidon5);
    UnloadTexture(Images -> profileB);
    UnloadTexture(Images -> ProfileB2);
    UnloadTexture(Images -> profileD);
    UnloadTexture(Images -> profileD2);
    UnloadTexture(Images -> profileH);
    UnloadTexture(Images -> profileH2);
    UnloadTexture(Images -> profileK);
    UnloadTexture(Images -> profileK2);
    UnloadTexture(Images -> profileP);
    UnloadTexture(Images -> profileP2);
    UnloadTexture(Images -> profileZ);
    UnloadTexture(Images -> profileZ2);
    UnloadTexture(Images -> settingsB);
    UnloadTexture(Images -> settingsD);
    UnloadTexture(Images -> settingsG);
    UnloadTexture(Images -> settingsH);
    UnloadTexture(Images -> settingsK);
    UnloadTexture(Images -> settingsP);
    UnloadTexture(Images -> settingsS);
    UnloadTexture(Images -> settingsZ);
    UnloadTexture(Images -> shopD);
    UnloadTexture(Images -> shopH);
    UnloadTexture(Images -> shopK);
    UnloadTexture(Images -> shopP);
    UnloadTexture(Images -> shopZ);
    UnloadTexture(Images -> soundOff);
    UnloadTexture(Images -> starD);
    UnloadTexture(Images -> starH);
    UnloadTexture(Images -> starK);
    UnloadTexture(Images -> starP);
    UnloadTexture(Images -> starZ);
    UnloadTexture(Images -> textD);
    UnloadTexture(Images -> textH);
    UnloadTexture(Images -> textK);
    UnloadTexture(Images -> textP);
    UnloadTexture(Images -> textZ);
    UnloadTexture(Images -> timer);
    UnloadTexture(Images -> timer2);
    UnloadTexture(Images -> zeus0);
    UnloadTexture(Images -> zeus1);
    UnloadTexture(Images -> zeus2);
    UnloadTexture(Images -> zeus3);
    UnloadTexture(Images -> zeus4);
    UnloadTexture(Images -> zeus5);

    return 0;
}