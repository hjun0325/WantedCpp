#include <iostream>
#include "Firefighter.h"
#include "FireChief.h"
#include "TraineeFirefighter.h"
#include "FireStation.h"
#include "Administrator.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 소방서 생성.
    FireStation* fireStation = new FireStation();

    // 관리자 생성.
    Administrator* taejun = new Administrator("관리자", "태준", "장");

	// 소방차 생성.
	Firetruck* truckOne = new Firetruck();

    // 소방관 생성.
	Firefighter* ronnie = new Firefighter("로니");
	Firefighter* james = new Firefighter("제임스");

    // 수습 소방관 생성 및 테스트.
    Firefighter* bill = new TraineeFirefighter("빌");
    bill->ExtinguishFire();

    // 소방서장 생성.
    Firechief* harry = new Firechief("해리", ronnie);

    // 출근.
    fireStation->ClockIn(taejun);
    fireStation->ClockIn(ronnie);
    fireStation->ClockIn(james);
    fireStation->ClockIn(bill);
    fireStation->ClockIn(harry);

    fireStation->RollCall();

    // 운전자 설정.
    truckOne->SetDriver(harry);
    
    // 소방차 이동.
    harry->Drive(truckOne, Point(200, 300));

    // 소방서장의 불끄기 위임.
    harry->ExtinguishFire();

    // 다형성.
    FirefighterBase* stillHarry = harry;
    stillHarry->ExtinguishFire();

    // 운전자 설정.
    truckOne->SetDriver(ronnie);

    // 소방차 이동.
    ronnie->Drive(truckOne, Point(10, 5));

    // 운전자 설정.
    truckOne->SetDriver(james);

    // 소방차 이동.
    james->Drive(truckOne, Point(20, -3));

    // 메모리 해제
    delete truckOne;
    delete ronnie;
    delete james;
    delete harry;
    delete bill;
    delete taejun;
    delete fireStation;

    std::cin.get();
}
