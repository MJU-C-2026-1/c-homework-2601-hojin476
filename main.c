/* 
  파일이름: 오운완 (오늘 운동 완료) 기록기
  작 성 자: 양호진, 26-04-27
  하 는 일:  운동후 결과를 기록하고, 오늘 제가 들어 올린 총 무게와 목표 무게의 차이를 계산하여 성취감을 얻기 위한 프로그램입니다.
*/

#include <stdio.h>

int main()
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
*/

  return 0;
}