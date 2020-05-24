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
	
	std::string project_str = "C:\\Users\\Олеся\\source\\repos\\TM_1_FUN_Lubinets\\Test\\";
	
	TEST_CLASS(Test)
	{
	public:
		//класс Cartoon
		TEST_METHOD(Cartoon_input_test1)
		{
			ifstream fin(project_str + "in_cartoon_1.txt");
			Cartoon* actual=new Cartoon;
			actual=InCartoon(fin);
			Cartoon* expected=new Cartoon;
			expected->way = Cartoon::DRAWN;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(Cartoon_input_test2)
		{
			ifstream in(project_str + "in_cartoon_2.txt");
			Cartoon* actual=new Cartoon;
			actual = InCartoon(in);
			Cartoon* expected = new Cartoon;
			expected->way = Cartoon::PUPPET;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(Cartoon_input_test3)
		{
			ifstream fin(project_str + "in_cartoon_3.txt");
			Cartoon* actual= new Cartoon;
			actual = InCartoon(fin);
			Cartoon* expected = new Cartoon;
			expected->way = Cartoon::PLASTICINE;
			Assert::AreEqual(int(expected->way), int(actual->way));
		}
		TEST_METHOD(Cartoon_output_test)
		{
			ofstream fout(project_str + "out_cartoon.txt");
			Cartoon* car=new Cartoon;
			car->way = Cartoon::PUPPET;
			OutCartoon(car, fout);
			fout.close();
			ifstream fin1(project_str + "out_cartoon_expected.txt");
			ifstream fin2(project_str + "out_cartoon.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		//класс Fiction
		TEST_METHOD(Fiction_input_test)
		{
			ifstream fin(project_str + "in_fiction.txt");
			Fiction* actual=new Fiction;
			actual=InFiction(fin);
			Fiction* expected = new Fiction;
			string* b = new string;
			 *b="Ivanov";
			expected->director = b;
			Assert::AreEqual(*(expected->director), *(actual->director));
		}		
		TEST_METHOD(Fiction_output_test)
		{
			ofstream out(project_str + "out_fiction.txt");
			Fiction* fic = new Fiction;
			string* b = new string;
			*b = "Ivanov";
			fic->director = b;
			OutFiction(fic, out);
			out.close();
			ifstream fin1(project_str + "out_fiction_expected.txt");
			ifstream fin2(project_str + "out_fiction.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		//класс Documentary
		TEST_METHOD(Documentary_input_test)
		{
			ifstream in(project_str + "in_documentary.txt");
			Documentary* actual=new Documentary;
			actual=InDocumentary(in);
			Documentary* expected=new Documentary;
			expected->year_release = 1976;
			Assert::AreEqual(expected->year_release, actual->year_release);
		}		
		TEST_METHOD(Documentary_output_test)
		{
			
				ofstream fout(project_str + "out_documentary.txt");
				Documentary* doc = new Documentary;
				doc->year_release = 2020;
				OutDocumentary(doc, fout);
				fout.close();
				ifstream fin1(project_str + "out_documentary_expected.txt");
				ifstream fin2(project_str + "out_documentary.txt");
				string expected;
				getline(fin1, expected, '\0');
				string actual;
				getline(fin2, actual, '\0');
				Assert::AreEqual(expected, actual);
			
		}
		//базовый класс Movie
		TEST_METHOD(Movie_input_test1)
		{
			ifstream in(project_str + "in_movie_1.txt");
			Movie* actual = new Movie;
			actual = InMovie(in);
			Movie* expected = new Movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = Movie::FICTION;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		TEST_METHOD(Movie_input_test2)
		{
			ifstream in(project_str + "in_movie_2.txt");
			Movie* actual = new Movie;
			actual = InMovie(in);
			Movie* expected = new Movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = Movie::CARTOON;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		TEST_METHOD(Movie_input_test3)
		{
			ifstream in(project_str + "in_movie_3.txt");
			Movie* actual = new Movie;
			actual = InMovie(in);
			Movie* expected = new Movie;
			string t = "Russia";
			expected->country = t;
			string t1 = "Title";
			expected->title = t1;
			expected->k = Movie::DOCUMENTARY;
			Assert::AreEqual(int(expected->k), int(actual->k));
			Assert::AreEqual(expected->title, actual->title);
			Assert::AreEqual(expected->country, actual->country);
		}
		
		TEST_METHOD(Movie_output_test)
		{
			ofstream fout(project_str + "out_movie.txt");
			Movie* mov = new Movie;
			string t = "Title";
			mov->title = t;
			t = "Russia";
			mov->country = t;
			mov->k = Movie::DOCUMENTARY;
			mov->documentary.year_release = 2020;
			OutMovie(*mov, fout);
			fout.close();
			ifstream fin1(project_str + "out_movie_expected.txt");
			ifstream fin2(project_str + "out_movie.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
		
		TEST_METHOD(Movie_count_test)
		{
			Movie* mov = new Movie;
			string t = "Название";
			mov->title = t;
			int actual= Count(*mov);
			int expected = 4;
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(Movie_compare_test)
		{
			Movie* mov1 = new Movie;
			string t = "Название";
			mov1->title = t;
			Movie* mov2 = new Movie;
		    t = "Названиее";
			mov2->title = t;
			bool expected = 1;
			bool actual = Compare(mov1, mov2);
			Assert::AreEqual(expected, actual);
		}
		//контейнер
		TEST_METHOD(container_output_test)
		{
			ifstream fin(project_str + "container_in.txt");
			ofstream fout(project_str + "container_out.txt");
			Container mas;
			Init(mas);
			In(mas, fin);
			Out(mas, fout);
			fout.close();
			ifstream fin1(project_str + "container_out_expected.txt");
			ifstream fin2(project_str + "container_out.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(container_filter_test)
		{
			ifstream fin(project_str + "container_in.txt");
			ofstream fout(project_str + "container_out_filter.txt");
			Container mas;
			Init(mas);
			In(mas, fin);
			OutOnlyCartoon(mas, fout);
			fout.close();
			ifstream fin1(project_str + "container_out_filer_expected.txt");
			ifstream fin2(project_str + "container_out_filter.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(container_sort_test)
		{
			ifstream fin(project_str + "container_in.txt");
			ofstream fout(project_str + "container_out_sort.txt");
			Container mas;
			Init(mas);
			In(mas, fin);
			Sort(mas);
			Out(mas, fout);
			fout.close();
			ifstream fin1(project_str + "container_out_sort_expected.txt");
			ifstream fin2(project_str + "container_out_sort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		
	};
}
