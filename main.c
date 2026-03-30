/* 
  파일이름: 오운완 (오늘 운동 완료) 기록기
  작 성 자: 양호진, 26-03-30
  하 는 일:  운동후 결과를 기록하고, 오늘 제가 들어 올린 총 무게와 목표 무게의 차이를 계산하여 성취감을 얻기 위한 프로그램입니다.
*/

#include <stdio.h>

int main()
{
//1 변수 선언 (자료형 3개 이상, 변수 5개 이상)
char user_name;
int goal_weight;
double benchpress;
double squat;
double body_weight;
double total_volume;
double gap;

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