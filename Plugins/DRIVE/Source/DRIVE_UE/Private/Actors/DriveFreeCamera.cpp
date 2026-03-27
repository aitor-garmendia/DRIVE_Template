#include "Actors/DriveFreeCamera.h"
#include "Engine/GameViewportClient.h"
#include "Engine/Engine.h"

ADriveFreeCamera::ADriveFreeCamera()
{
}

void ADriveFreeCamera::ChangeViewMode(EViewModeIndex ViewMode) const
{
    if (GEngine)
    {
        if (UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull))
        {
            if (UGameViewportClient* ViewportClient = World->GetGameViewport())
                ViewportClient->SetViewMode(ViewMode);
        }
    }
}