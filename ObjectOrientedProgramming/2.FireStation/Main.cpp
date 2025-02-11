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

    // �ҹ漭 ����.
    FireStation* fireStation = new FireStation();

    // ������ ����.
    Administrator* taejun = new Administrator("������", "����", "��");

	// �ҹ��� ����.
	Firetruck* truckOne = new Firetruck();

    // �ҹ�� ����.
	Firefighter* ronnie = new Firefighter("�δ�");
	Firefighter* james = new Firefighter("���ӽ�");

    // ���� �ҹ�� ���� �� �׽�Ʈ.
    Firefighter* bill = new TraineeFirefighter("��");
    bill->ExtinguishFire();

    // �ҹ漭�� ����.
    Firechief* harry = new Firechief("�ظ�", ronnie);

    // ���.
    fireStation->ClockIn(taejun);
    fireStation->ClockIn(ronnie);
    fireStation->ClockIn(james);
    fireStation->ClockIn(bill);
    fireStation->ClockIn(harry);

    fireStation->RollCall();

    // ������ ����.
    truckOne->SetDriver(harry);
    
    // �ҹ��� �̵�.
    harry->Drive(truckOne, Point(200, 300));

    // �ҹ漭���� �Ҳ��� ����.
    harry->ExtinguishFire();

    // ������.
    FirefighterBase* stillHarry = harry;
    stillHarry->ExtinguishFire();

    // ������ ����.
    truckOne->SetDriver(ronnie);

    // �ҹ��� �̵�.
    ronnie->Drive(truckOne, Point(10, 5));

    // ������ ����.
    truckOne->SetDriver(james);

    // �ҹ��� �̵�.
    james->Drive(truckOne, Point(20, -3));

    // �޸� ����
    delete truckOne;
    delete ronnie;
    delete james;
    delete harry;
    delete bill;
    delete taejun;
    delete fireStation;

    std::cin.get();
}
