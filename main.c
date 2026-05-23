/* 
  파일이름: 오운완 (오늘 운동 완료) 기록기
  작 성 자: 양호진, 26-05-23
  하 는 일:  운동후 결과를 기록하고, 오늘 제가 들어 올린 총 무게와 목표 무게의 차이를 계산하여 성취감을 얻기 위한 프로그램입니다.
*/

#include <stdio.h>

// 변수 선언
double total_volume = 0.0;

// 함수 선언
void display_menu();
void record_workout();
double calculate_gap (int goal, double total);
int check_grade (double body_w);

int main()
{
  int choice;
  int goal_weight;
  double body_weight;
  double gap = 0.0;

  printf("=====================================\n");
  printf("\t오운완 기록기 v3.0\n");
  printf("=====================================\n");

  //올바른 몸무게 입력할 때까지 무한 반복
  while (1)
  {
    printf("현재 몸무게(kg)를 입력하세요 : ");
    scanf("%lf", &body_weight);

    if (body_weight > 0)
    {
      break; // 0보다 큰 값이므로 탈출
    }
    else
    {
      printf("오류 : 몸무게는 0보다 커야 합니다. 다시 입력해주세요. \n\n");
    }
  }

  // 올바른 중량 입력할 때까지 무한 반복
  while(1)
  {
    printf("목표 총 중량 (정수) 입력 : ");
    scanf("%d", &goal_weight);

    if (goal_weight > 0)
    {
      break; // 0보다 큰 값이므로 탈출
    }
    else
    {
      printf("오류 : 목표 중량은 0보다 커야 합니다. 다시 입력해주세요. \n\n");
    }
  }

  // 무한 루프를 활용하여 메인 메뉴 구현
  while (1)
  {
    // 함수 호출
    display_menu();
    printf("메뉴 선택 : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        // 운동 기록 함수 호출
        record_workout();
    }
    else if (choice == 2)
    {
        // 분석 및 등급 확인
        printf("\n---현재 상태 분석---\n");
        printf("현재까지 기록된 총 중량 : %.1fkg\n", total_volume);

        // return 문이 있는 함수 호출
        check_grade(body_weight);

        // 매개변수 (goal_weight, total_volume)를 전달하는 함수 호출
        gap = calculate_gap(goal_weight, total_volume);

        if (total_volume >= goal_weight)
        {
          printf("대단합니다! 목표 중량을 달성했습니다!\n");
        }
        else
        {
          printf("목표까지 %.1fkg 남았습니다. 조금만 더 힘내세요!\n", gap);
        }
    }  
      else if (choice == 3)
      {
        // 종료 메뉴를 선택할 때 break
        printf("프로그램을 종료합니다. 오늘도 득근하세요!\n");
        break;
      }
    else
    {
      printf("잘못된 번호입니다. 1~3번 중에서 선택하세요.\n");
    }      
  }
  
  return 0;
}

// 메인 메뉴를 출력하는 함수
void display_menu()
{
  printf("\n============= 메 인 메 뉴 =============\n");
  printf("1. 당일 운동 중량 기록하기\n");
  printf("2. 현재 총합 충량 및 등급 분석\n");
  printf("3. 프로그램 종료\n");
  printf("=========================================\n");
}

// 운동 중량을 입력받아 기록하는 함수

void record_workout()
{
  double benchpress;
  double squat;

  printf("\n--- 운동 중량 입력 ---\n");
  printf("벤치프레스 무게(kg) : ");
  scanf("%lf", &benchpress);
  printf("스쿼트 무게(kg) : ");
  scanf("%lf", &squat);

  if (benchpress > 0 && squat > 0)
  {
    // total_volume 값 업데이트
    total_volume = benchpress + squat;
    printf("기록 완료! 오늘의 총 중량이 %.1fkg으로 업데이트 되었습니다!\n", total_volume);
  }
  else
  {
    printf("잘못된 입력입니다. 0보다 큰 값을 입력하세요. \n");
  }

}

// 목표 중량과 현재 중량의 차이를 계산, 매개변수로 goal과 total을 전달 받음
double calculate_gap(int goal, double total)
{
  return (double)goal - total; // 계산 결과를 반환
}

// 체중 대비 중량비를 계산하여 등급 판별
int check_grade(double body_w)
{

  double ratio = total_volume / body_w;
  printf("현재 몸무게 대비 중량비 : %.2f\n", ratio);

  if (ratio >= 2.0)
  {
    printf("현재 등급 : [ 헬창 ] (대단합니다! 걸어다니는 머신이시네요!)\n");
  }
  else if (ratio >= 1.0)
  {
    printf("현재 등급 : [ 득근자 ] (열심히 하고 계십니다! 조금만 더!)\n");
  }
  else
  {
    printf("현재 등급 : [ 헬린이 ] (성장 가능성이 무궁무진합니다!)\n");
  }

  return 1; // 정상적으로 등급 출력을 완료했음을 의미하는 1 반환
}
/*
{
//1 변수 선언 (자료형 3개 이상, 변수 5개 이상)
char user_name;
int goal_weight;
int choice;
double benchpress;
double squat;
double body_weight;
double total_volume;
double gap;
double ratio;

printf("============================================\n");
printf("\t오운완(오늘 운동 완료) 기록기\n");
printf("============================================\n");

//2 입력 받기
printf("사용자의 이니셜을 입력하세요 (한 글자) : ");
scanf(" %c", &user_name);

printf("현재 몸무게(kg)를 입력하세요 : ");
scanf("%lf", &body_weight);

printf("목표 총 중량(정수 입력) : ");
scanf("%d", &goal_weight);

printf("벤치프레스 무게(kg)를 입력하세요 : ");
scanf("%lf", &benchpress);

printf("스쿼트 무게(kg)를 입력하세요 : ");
scanf("%lf", &squat);

printf("\n============================================\n");

//3.1 산술 연산
total_volume = benchpress + squat;
gap = goal_weight - total_volume;
ratio = total_volume / body_weight;

//3.2 조건문
if (benchpress > 0 && squat > 0)
{
  //다중 조건문
  if (ratio >= 2.0)
  {
    printf("등급: 헬창 (대단합니다!)\n");

  }
  else if(ratio >= 1.0)
  {
    printf("등급: 득근자 (열심히 하시네요!)\n");
  }
  else
  {
    printf("등급: 헬린이 (열심히 합시다!)\n");
  }

  // 목표 달성 여부 확인
  if (total_volume >= goal_weight)
  {
    printf("목표 중량도 달성했습니다!\n");
  }
  else
  {
    printf("아쉽습니다 목표 중량까지 %lfkg 남았습니다\n", gap);
  }

  // [switch-case 문] 메뉴 선택 기능
  printf("\n추가 확인 메뉴 (1: 상세 기록, 2: 조언 보기, 3: 종료) : ");
  scanf("%d", &choice);
  
  switch (choice)
  {
    case 1:
      printf("\n--- 상세 기록 ---\n");
      printf("%c님의 오늘 운동량: %.1fkg\n", user_name, total_volume);
      break;

    case 2:
      printf("\n[오늘의 팁]\n");
      if (ratio < 1.0)
        printf("기초 체력을 더 키워보세요!\n");
      else
        printf("정말 대단한 운동량입니다!\n");
      break;

    case 3:
        printf("프로그램을 종료합니다.\n");
        break;
    default:
        printf("잘못된 번호입니다.\n");
        break;
  }
}
    //벤치프레스, 스쿼트 값이 0보다 작을 때
else
{
  printf("입력값이 잘못되었습니다. 0보다 큰 값을 입력하세요.\n");
}

*/

/*
1차 과제

//3 산술 연산
total_volume = benchpress + squat;
gap = goal_weight - total_volume;

//4 결과 출력 (printf 사용)
printf("\n============================================\n");
printf("트레이너 %c님의 오늘 운동 기록\n", user_name);
printf("현재 체중: %.2fkg\n", body_weight);
printf("목표 총 중량: %dkg\n", goal_weight);
printf("오늘 들어올린 총 무게: %.1f\n", total_volume);
printf("목표 달성까지 %.1fkg 남았습니다!\n", gap);
printf("============================================\n");
printf("\t  오운완! 수고하셨습니다!\n");


  return 0;
}
*/