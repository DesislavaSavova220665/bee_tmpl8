#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "surface.h" // For rendering assets

namespace Tmpl8
{

	class MainMenu
	{
    public:
        // Constructor
        MainMenu();

        // Destructor
        ~MainMenu();

        // Method to initialize the main menu
        void init(Surface* screen, const std::string& backgroundImage, const std::string& playButtonImage);

        // Method to update the main menu (e.g., handle input)
        void update(float deltaTime, Surface* screen);

        // Method to render the main menu
        void render(Surface* screen);

        // Method to check if the play button is clicked
        bool isPlayButtonClicked(int mouseX, int mouseY) const;

    private:
        // Background image asset
        Surface background;

        // Play button image asset
        Surface playButton;

        // Position and size of the play button
        int playButtonX;
        int playButtonY;
        int playButtonWidth;
        int playButtonHeight;
	};

#endif // MAINMENU_H
}

