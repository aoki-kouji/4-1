#include <iostream>
using namespace std;


// ����N���X
class MyClass {
public:
	void Update();

	void a ();
	void b ();
	void c ();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (MyClass::* table[])();

private:
	// �����o�֐��|�C���^�̃e�[�u�����Q�Ƃ���C���f�b�N�X
	int index = 0;
};

void MyClass::a() {
	cout << "�G�̐ڋ߁I" << endl;
}

void MyClass::b() {
	cout << "�G�̍U���I" << endl;
}

void MyClass::c() {
	cout << "�G�̌�ށI" << endl;
}

void MyClass::Update() {

	// �֐��|�C���^�̃e�[�u������֐������s
	(this->*table[index])();

	int num;

	puts("���̍s����");
	scanf_s("%d", &num);

	if (num==0) {
		index++;
		if (index > 2)
			index = 0;
	}
}

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (MyClass::* MyClass::table[])() = {
  &MyClass::a, // �C���f�b�N�X�ԍ�0
  &MyClass::b, // �C���f�b�N�X�ԍ�1
  &MyClass::c  // �C���f�b�N�X�ԍ�2
};


int main()
{
	MyClass my;

	while (1) {
		my.Update();
	}

	return 0;
}