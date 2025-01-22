#pragma once

#include <Engine/Engine.h>

class Level;
class MainMenuLeve;
class WeaponSetupMenuLevel;
class PauseMenuLevel;
class MainGameLevel;
class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// 싱글톤 객체 접근 함수.
	static Game& Get() { return *instance; }


	// 레벨을 전환하고 설정하는 함수.
	void ChangeLevel(Level * level);

	// 기존의 mainGameLevel을 지우고 다시 새 레벨을 만드는 함수.
	void RestartGame(Level* currentLevel);

	// 메뉴 레벨 Getter.
	Level* GetMainMenuLevel()			const;
	Level* GetWeaponSetupMenuLevel()	const;
	Level* GetPauseMenuLevel()			const;

	// 게임 레벨 Getter.
	Level*	GetMainGameLevel()			const;


private:

	// 싱글톤 구현을 위한 전역 변수 선언..
	static Game* instance; 

	// 메뉴 레벨
	Level* mainMenuLevel;			// 메인 메뉴 레벨.
	Level* weaponSetupMenuLevel;	// 무기 설정 메뉴 레벨.
	Level* pauseMenuLevel;			// 게임 일시 정지 메뉴.

	// 게임 레벨
	Level* mainGameLevel;			// 메인 게임 레벨.
};