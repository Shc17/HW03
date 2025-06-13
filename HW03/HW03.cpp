#include<iostream>

using namespace std;

template <typename T>
class SimpleVector 
{
public:
    SimpleVector() : Size(0), Capacity(10) // 기본 생성자 초기화 값 설정
    {
        data = new T[Capacity];
    }

    ~SimpleVector()  //소멸자
    {
        delete[] data; // 배열 메모리 해제
        data = nullptr;// 한 번더 메모리 해제 확인
    }

    void push_back(const T& value)// 복사가 아닌 원본 값
    {
        if (Size < Capacity)
        {
            data[Size] = value;
            Size++;
        }
        else
        {
            cout << "용량이 가득 찾습니다. 용량: " << Size << "/" << Capacity << endl;
        }
      
      
    }

    void pop_back()
    {
        if (Size > 0)
        {
            Size--;
        }
    }

    int size() //Size 값 내보내기
    {
        return Size;
    }
    
    int capacity() //Capacity 값 내보내기
    {
        return Capacity;
    }

private:
    T* data;               // 데이터를 저장할 배열을 가리키는 포인터
    int Size;              // 현재 저장된 실제 요소의 개수
    int Capacity;          // 할당된 메모리의 총 용량

};

int main() 
{
    SimpleVector<int> myVector;
    cout << "SimpleVector 생성 최대 용량: " << myVector.capacity()<< endl;
    int choice;
    
    while (true) //무한루프
    {
        cout << "1. 데이터 추가 (push_back)" << endl;
        cout << "2. 마지막 데이터 삭제 (pop_back)" << endl;
        cout << "3. 모든 데이터 및 상태 보기" << endl;
        cout << "4. 종료" << endl;
        cout << "선택: ";
        cin >> choice;
        
        // 데이터 추가 (push_back)
        if (choice == 1)
        {
            int num;
            cout << "몇 개의 숫자를 입력하시겠습니까? : ";
            cin >> num;

            if (num > 0)
            {
                cout << num << " 개의 숫자를 입력하세요." << endl; //for 문에 입력하니 계속 출력되서 밖으로 꺼냄

                for (int i = 0; i < num; i++)
                {
                    int Num;
                    cout << i + 1 << "번 째 숫자: ";
                    cin >> Num;
                    myVector.push_back(Num);
                }
            }

            else 
            {
                cout << "0을 입력하셔서 처음으로 되돌아갑니다." << endl;
            }
        }
        
        //마지막 데이터 삭제 (pop_back)
        else if (choice == 2)   
        {
            if (myVector.size() > 0)  //여기서 오류가 한번 났었는데 이유는 Size 함수에서 잘못된 방식으로 코드가 짜여짐
            {
                cout << "마지막 데이터가 삭제 되었습니다." << endl;
                myVector.pop_back();
            }
            else
            {
                cout << "데이터가 없습니다.추가하세요." << endl;
            }
        }
        
        //모든 데이터 및 상태 보기 , 값 가져와서 출력
        else if (choice == 3) 
        {
            cout << "최종 벡터 크기: " << myVector.size() << endl;
            cout << "최종 벡터 용량: " << myVector.capacity() << endl;
        }
        
        //종료 
        else if (choice == 4)
        {
            cout << "프로그램을 종료합니다." << endl;
            break; // while 문에서 무한루프를 빠져나감
        }
        
        // 오류
        else
        {
            cout << "1, 2, 3, 4번 중에 선택하세요." << endl;
        }
     
    }
    
    return 0;
}