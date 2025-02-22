#include "C0301MyString.h"

using namespace std;

// ��� �ִ� MyString() ����
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// �� �ڿ� �� ĳ����'\0'�� ��� �ִ� ���ڿ��κ��� �ʱ�ȭ
MyString::MyString(const char* init)
{
	size_ = 0;
	while (init[size_] != '\0')
		size_++;

	str_ = new char[size_];
	memcpy(str_, init, size_);
}

// MyString�� �ٸ� instance�κ��� �ʱ�ȭ
MyString::MyString(const MyString& str)
{
	// �⺻ ���� �����ڴ� ������ �ּҸ� �����ϱ� ������ 
	// �Ҹ�� ���� �߻�
	// ���⼭�� ���� �޸𸮸� �Ҵ� �޾Ƽ� ����
	size_ = str.size_;
	str_ = new char[size_];
	memcpy(str_, str.str_, size_);
}

MyString::~MyString()
{
	// �޸� ����
	if (str_ != nullptr)
	{
		delete[] str_;
		str_ = nullptr;
		size_ = 0;
	}
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // ���ǻ� ����& ���
{
	// ��Ʈ: str.str_, str.size_ ����
	if (size_ != str.size_)
		return false;

	for (int i = 0; i < this->size_; i++)
		if (str_[i] != str.str_[i])
			return false;

	return true;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// �޸� ���Ҵ�� ���� ���� �ִ� ���� ����
	if (new_size != size_)
	{
		char* new_str = new char[new_size];

		/*memcpy(new_str, str_, new_size);*/
		for (int i = 0; i < (new_size < size_ ? new_size : size_); i++)
			new_str[i] = str_[i];

		delete[] str_;
		str_ = new_str;
		size_ = new_size;
	}
}

// �ε��� start��ġ�� ���ں��� num���� ���ڷ� ���ο� ���ڿ� �����
MyString MyString::Substr(int start, int num)
{
	// ������ �ε���: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // ������ �ܼ��ϰ� ����� ���� ����

	MyString temp;

	// TODO:
	temp.Resize(num);

	for (int i = 0; i < num; i++)
		temp.str_[i] = this->str_[start + i];

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;

	// TODO: 
	temp.Resize(size_ + app_str.size_);
	memcpy(temp.str_, str_, size_);
	memcpy(&temp.str_[size_], app_str.str_, app_str.size_);

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;

	temp.Resize(size_ + t.size_);

	for (int i = 0; i < start; i++)
		temp.str_[i] = str_[i];

	for (int i = start; i < start + t.size_; i++)
		temp.str_[i] = t.str_[i - start];

	for (int i = start + t.size_; i < size_ + t.size_; i++)
		temp.str_[i] = str_[i - t.size_];

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO:
	//for (int i = 0; i <= size_ - pat.size_; i++)
	//{
	//	if (str_[i] == pat.str_[0])
	//	{
	//		int sizeCounter = 0;
	//		for (int j = 0; j < pat.size_; j++)
	//		{
	//			if (str_[i + j] == pat.str_[j])
	//			{
	//				sizeCounter++;
	//				if (sizeCounter == pat.size_)
	//				{
	//					return i;
	//				}
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//	}
	//}

	for (int start = 0; start <= Length() - pat.Length(); start++)
	{
		for (int j = 0; j < pat.Length(); j++)
		{
			if (str_[start + j] != pat.str_[j])
				break;

			if (j == pat.Length() - 1)
				return start;
		}
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}
