#include "globalController.h"
#include "Character.h"

GlobalController::GlobalController()
{
    if (IsWindowFullscreen())
    {
        ToggleFullscreen();
    }
    currentWorld = World();
    AddCharacter(new Character());
}
GlobalController::~GlobalController()
{
    for (int i = 0; i < (int)characters.size(); i++)
    {
        RemoveCharacter(characters[i]);
    }
}
void GlobalController::AddCharacter(BaseCharacter* character)
{
    characters.push_back(character);
}
void GlobalController::RemoveCharacter(BaseCharacter* character)
{
    character->Destroy();
    //std::remove(characters.begin(), characters.end(), character);
    for (int i = 0; i < (int)characters.size(); i++)
    {
        if (*characters[i] == character)
        {
            characters.erase(characters.begin() + i);
        }
    }
}
void GlobalController::Update()
{
    currentWorld.Tick();
    for (int i = 0; i < (int)characters.size(); i++)
    {
        characters[i]->Tick();
    }
}