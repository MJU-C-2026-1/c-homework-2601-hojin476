/* 
  파일이름: 오운완 (오늘 운동 완료) 기록기
  작 성 자: 양호진, 26-05-23
  하 는 일:  운동후 결과를 기록하고, 오늘 제가 들어 올린 총 무게와 목표 무게의 차이를 계산하여 성취감을 얻기 위한 프로그램입니다.
*/

#include <stdio.h>

// 변수 선언
double total_volume = 0.0;

//데이터 누적
double workout_history[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

// 함수 선언
void display_menu();
void record_workout();
double calculate_gap (int goal, double total);
int check_grade (double body_w);
void record_history_ptr(double*ptr);
void print_history_index();
double calculate_history_total(double arr[]);


int main()
{
  int choice;
  int goal_weight;
  double body_weight;
  double gap = 0.0;
  double history_total = 0.0;

  printf("=====================================\n");
  printf("\t오운완 기록기 v4.0\n");
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
      record_history_ptr(workout_history);
    }  
      else if (choice == 3)
    {
      print_history_index();
    }
    else if (choice == 4)
    {
      printf("\n---현재 상태 분석---\n");
			printf("오늘 기록된 당일 총 중량 : %.1fkg\n", total_volume);

      check_grade(body_weight);

      gap = calculate_gap(goal_weight, total_volume);

			if (total_volume >= goal_weight)
			{
				printf("대단합니다! 오늘 목표 중량을 달성했습니다!\n");
			}
			else
			{
				printf("오늘 목표까지 %.1fkg 남았습니다. 조금만 더 힘내세요!\n", gap);
			}
			
			history_total = calculate_history_total(workout_history);
			printf("\n [5일 누적 데이터 분석] 총 누적 중량 : %.1fkg (목표: %dkg)\n", history_total, goal_weight * 5);
    }
    else if (choice == 5)
    {
      printf("프로그램을 종료합니다. 오늘도 득근하세요!\n");
      break;
    }
    else
    {
      printf("잘못된 번호입니다. 1~5번 중에서 선택하세요.\n");
    }
  }
  return 0;
}

// 메인 메뉴를 출력하는 함수
void display_menu()
{
  printf("\n============= 메 인 메 뉴 =============\n");
  printf("1. 당일 운동 중량 기록하기\n");
  printf("2. 5일간의 운동 무게 기록/변경\n");
  printf("3. 5일간 운동 기록 리스트 조회\n");
  printf("4. 현재 총합 중량 및 등급 분석\n");
  printf("5. 프로그램 종료\n");
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

void record_history_ptr(double *ptr)
{
  printf("\n 5일간의 기록 변경 로직이 실행됩니다...\n");
  printf("--- 최근 5일간의 중량(kg) 입력 ---\n");

  for (int i = 0; i < 5; i++)
  {
    printf("%d일차 총 중량 입력 : ", i+1);
    scanf("%lf", (ptr + i));
  }
  printf("5일간의 데이터가 성공적으로 변경되었습니다. \n");
  printf("메인 메뉴로 돌아갑니다.\n");
}

void print_history_index()
{
  printf("\n 5일 기록 리스트 조회 로직이 실행됩니다...\n");
  printf("--- 최근 5일간의 운동 기록 리스트 ---\n");

  for (int i = 0; i <5; i++)
  {
    printf("[%d일차 기록] : %.1f kg \n", i + 1, workout_history[i]);
  }
  printf("----------------------------------------------------\n");
  printf("메인 메뉴로 돌아갑니다.\n");
}

double calculate_history_total (double arr[])
{
  double sum = 0.0;

  for (int i = 0; i < 5; i++)
  {
    sum += arr[i];
  }
  return sum;
}