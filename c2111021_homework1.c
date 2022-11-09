#include <stdio.h>
float per_a, per_b, per_c;

int PercentageChecker(int a, int b, int c)
{
    if (per_a + per_b + per_c != 100)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

float setHomeworkPercentage()
{
    printf("Please enter homewrok percentages: ");
    scanf("%f", &per_a);

    return per_a;
}

float setMidtermPercentage()
{
    printf("Please enter midterm percentages: ");
    scanf("%f", &per_b);

    return per_b;
}

float setFinalPercentage()
{
    printf("Please enter final percentages: ");
    scanf("%f", &per_c);

    return per_c;
}

void setPercentages()
{
    printf("Please set homework, midterm and final percentages first.\n");

    setHomeworkPercentage();
    setMidtermPercentage();
    setFinalPercentage();
}

int getTotalGrade(int a, int b, int c)
{
    int average;

    average = ((float)a / 100.0 * per_a) + ((float)b / 100.0 * per_b) + ((float)c / 100.0 * per_c);
    average = (int)average;
    return average;
}

char getLetterGrade(int a)
{
    char note;
    if (a <= 100 && a >= 90)
    {
        note = 'A';
        return note;
    }

    else if (a <= 89 && a >= 75)
    {
        note = 'B';
        return note;
    }

    if (a <= 74 && a >= 60)
    {
        note = 'C';
        return note;
    }

    if (a <= 59 && a >= 45)
    {
        note = 'D';
        return note;
    }

    if (a <= 44 && a >= 0)
    {
        note = 'F';
        return note;
    }
}

int main(void)
{
    char student;
    float sum1 = 0, sum2 = 0, sum3 = 0;
    int hw, mt, fl, note_1, note_2, note_3, num = 1;
    setPercentages();

    if (PercentageChecker(per_a, per_b, per_c) == 0)
    {
        printf("Invalid.");
    }

    else
    {
        printf("Done.\n\n");
        do
        {
            printf("(Student%d) Enter homework, midterm and final grades for first course: ", num);
            scanf("%d %d %d", &hw, &mt, &fl);

            note_1 = getTotalGrade(hw, mt, fl);

            printf("(Student%d) Enter homework, midterm and final grades for second course: ", num);
            scanf("%d %d %d", &hw, &mt, &fl);

            note_2 = getTotalGrade(hw, mt, fl);

            printf("(Student%d) Enter homework, midterm and final grades for third course: ", num);
            scanf("%d %d %d", &hw, &mt, &fl);

            note_3 = getTotalGrade(hw, mt, fl);

            printf("(Student%d)Grade for first course is: %c (%d)\n", num, getLetterGrade(note_1), note_1);
            printf("(Student%d)Grade for second course is: %c (%d)\n", num, getLetterGrade(note_2), note_2);
            printf("(Student%d)Grade for third course is: %c (%d)\n", num, getLetterGrade(note_3), note_3);

            num++;
            sum1 += note_1;
            sum2 += note_2;
            sum3 += note_3;

            printf("Do you want to enter an another student? (y/n):");
            scanf(" %c", &student);

        } while (student == 'y');

        printf("\nFirst course average: %f\n", sum1 / ((float)num - 1.0));
        printf("Second course average: %f\n", sum2 / ((float)num - 1.0));
        printf("Third course average: %f\n", sum3 / ((float)num - 1.0));
        printf("Bye!");
    }

    return 0;
}