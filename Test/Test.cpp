#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>


#include "Cartoon.cpp"
#include "container.cpp"
#include "documentary.cpp"
#include "fiction.cpp"
#include "movie.cpp"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		//класс cartoon
		TEST_METHOD(cartoon_input_test1)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_cartoon_1.txt");
			cartoon* actual=new cartoon;
			actual=In_cartoon(fin);
			cartoon* expected=new cartoon;
			expected->way = cartoon::DRAWN;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(cartoon_input_test2)
		{
			ifstream in("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_cartoon_2.txt");
			cartoon* actual=new cartoon;
			actual = In_cartoon(in);
			cartoon* expected = new cartoon;
			expected->way = cartoon::PUPPET;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(cartoon_input_test3)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_cartoon_3.txt");
			cartoon* actual= new cartoon;
			actual = In_cartoon(fin);
			cartoon* expected = new cartoon;
			expected->way = cartoon::PLASTICINE;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(cartoon_output_test)
		{
			ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_cartoon.txt");
			cartoon* car=new cartoon;
			car->way = cartoon::PUPPET;
			Out_cartoon(car, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_cartoon_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_cartoon.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		//класс fiction
		TEST_METHOD(fiction_input_test)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_fiction.txt");
			fiction* actual=new fiction;
			actual=In_fiction(fin);
			fiction* expected = new fiction;
			string* b = new string;
			 *b="Ivanov";
			expected->director = b;
			Assert::AreEqual(*(expected->director), *(actual->director));
		}		
		TEST_METHOD(fiction_output_test)
		{
			ofstream out("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_fiction.txt");
			fiction* fic = new fiction;
			string* b = new string;
			*b = "Ivanov";
			fic->director = b;
			Out_fiction(fic, out);
			out.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_fiction_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_fiction.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		//класс documentary
		TEST_METHOD(documentary_input_test)
		{
			ifstream in("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_documentary.txt");
			documentary* actual=new documentary;
			actual=In_documentary(in);
			documentary* expected=new documentary;
			expected->year_release = 1976;
			Assert::AreEqual(expected->year_release, actual->year_release);
		}		
		TEST_METHOD(documentary_output_test)
		{
			
				ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_documentary.txt");
				documentary* doc = new documentary;
				doc->year_release = 2020;
				Out_documentary(doc, fout);
				fout.close();
				ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_documentary_expected.txt");
				ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_documentary.txt");
				string expected;
				getline(fin1, expected, '\0');
				string actual;
				getline(fin2, actual, '\0');
				Assert::AreEqual(expected, actual);
			
		}
		//базовый класс movie
		TEST_METHOD(movie_input_test1)
		{
			ifstream in("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_movie_1.txt");
			movie* actual = new movie;
			actual = In_movie(in);
			movie* expected = new movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = movie::FICTION;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		TEST_METHOD(movie_input_test2)
		{
			ifstream in("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_movie_2.txt");
			movie* actual = new movie;
			actual = In_movie(in);
			movie* expected = new movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = movie::CARTOON;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		TEST_METHOD(movie_input_test3)
		{
			ifstream in("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\in_movie_3.txt");
			movie* actual = new movie;
			actual = In_movie(in);
			movie* expected = new movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = movie::DOCUMENTARY;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		
		TEST_METHOD(movie_output_test)
		{
			ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_movie.txt");
			movie* mov = new movie;
			string t = "Title";
			mov->title = t;
			t = "Russia";
			mov->country = t;
			mov->k = movie::DOCUMENTARY;
			mov->documentary.year_release = 2020;
			Out_movie(*mov, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_movie_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\out_movie.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
		
		TEST_METHOD(movie_count_test)
		{
			movie* mov = new movie;
			string t = "Название";
			mov->title = t;
			int actual= Count(*mov);
			int expected = 4;
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(movie_compare_test)
		{
			movie* mov1 = new movie;
			string t = "Название";
			mov1->title = t;
			movie* mov2 = new movie;
		    t = "Названиее";
			mov2->title = t;
			bool expected = 1;
			bool actual = Compare(mov1, mov2);
			Assert::AreEqual(expected, actual);
		}
		//контейнер
		TEST_METHOD(container_output_test)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_in.txt");
			ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out.txt");
			container mas;
			Init(mas);
			In(mas, fin);
			Out(mas, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(container_filter_test)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_in.txt");
			ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_filter.txt");
			container mas;
			Init(mas);
			In(mas, fin);
			Out_Only_Cartoon(mas, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_filer_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_filter.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(container_sort_test)
		{
			ifstream fin("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_in.txt");
			ofstream fout("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_sort.txt");
			container mas;
			Init(mas);
			In(mas, fin);
			Sort(mas);
			Out(mas, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_sort_expected.txt");
			ifstream fin2("C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\container_out_sort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
	};
}
