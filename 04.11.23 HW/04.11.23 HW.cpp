#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

struct Movie
{
    string title;
    string director;
    string genre;
    int userRating;
    double cost;
};

const int storeSize = 5;
Movie movieStore[storeSize];

void displayStore(int size);
void displayMovie(int index);

void addMovieInfo(string title, string director, string genre, int userRating, double cost, int index)
{
    movieStore[index] = { title, director, genre, userRating, cost };
}

string toLowerCase(string input)
{
    string output = input;
    for (int i = 0; i < input.length(); i++)
    {
        output[i] = tolower(input[i]);
    }
    return output;
}

void searchByTitle(string title)
{
    for (int i = 1; i <= storeSize; i++)
    {
        if (toLowerCase(movieStore[i].title) == toLowerCase(title))
        {
            cout << endl << "Movie found." << endl << "Movie Information: " << endl;
            displayMovie(i);
        }
    }
}

void searchByDirector(string director)
{
    for (int i = 1; i <= storeSize; i++)
    {
        if (toLowerCase(movieStore[i].director) == toLowerCase(director))
        {
            cout << endl << "Movie found." << endl << "Movie Information: " << endl;
            displayMovie(i);
        }
    }
}

void searchByGenre(string genre)
{
    for (int i = 1; i <= storeSize; i++)
    {
        if (toLowerCase(movieStore[i].genre) == toLowerCase(genre))
        {
            cout << endl << "Movie found." << endl << "Movie Information: " << endl;
            displayMovie(i);
        }
    }
}

void mostPopularMovieInGenre(string genre)
{
    int maxRating = 0;
    string popularMovie;
    for (int i = 1; i <= storeSize; i++)
    {
        if (toLowerCase(movieStore[i].genre) == toLowerCase(genre) && movieStore[i].userRating > maxRating)
        {
            maxRating = movieStore[i].userRating;
            popularMovie = movieStore[i].title;
        }
    }
    cout << endl << endl << "Most Popular Movie in genre = " << popularMovie << endl;
    cout << "Max Rating = " << maxRating << endl << endl << endl;
}

void displayMovie(int index)
{
    cout << "Title: " << movieStore[index].title << endl;
    cout << "Director: " << movieStore[index].director << endl;
    cout << "Genre: " << movieStore[index].genre << endl;
    cout << "Rating: " << movieStore[index].userRating << endl;
    cout << "Cost: " << movieStore[index].cost << endl;
    cout << "------------------------" << endl;
}

void displayStore()
{
    for (int i = 1; i <= storeSize; i++)
    {
        cout << "Title: " << movieStore[i].title << endl;
        cout << "Director: " << movieStore[i].director << endl;
        cout << "Genre: " << movieStore[i].genre << endl;
        cout << "Rating: " << movieStore[i].userRating << endl;
        cout << "Cost: " << movieStore[i].cost << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    int index = 1;
    addMovieInfo("Sponge Bob", "Dean DeBlois", "Animated", 8, 500, index);
    addMovieInfo("The Conjuring", "James Wan", "Horror", 9, 2000, ++index);
    addMovieInfo("Inception", "Christopher Nolan", "Sci-Fi", 10, 120, ++index);
    addMovieInfo("Finding Nemo", "Andrew Stanton", "Animated", 7, 2300, ++index);
    addMovieInfo("The Matrix", "Lana Wachowski", "Sci-Fi", 9, 1400, ++index);

    string name;
    string director;
    string genre;
    int n = 1;
    char* buffer = (char*)malloc(128);
    while (n != 0)
    {
        cout << "Enter 1,if you want to find movie by the name." << endl;
        cout << "Enter 2,if you want to find movie by the director." << endl;
        cout << "Enter 3,if you want to find movie by the genre." << endl;
        cout << "Enter 0,if you dont want to find anything." << endl;
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Enter name of movie: ";
            cin.getline(buffer, 128, '\n');
            cin.getline(buffer, 128, '\n');
            name = string(buffer);
            free(buffer);
            searchByTitle(name);
            break;
        case 2:
            cout << "Enter director of movie: ";
            cin.getline(buffer, 128, '\n');
            cin.getline(buffer, 128, '\n');
            director = string(buffer);
            free(buffer);

            searchByDirector(director);
            break;
        case 3:
            cout << "Enter genre of movie: ";
            cin >> genre;
            searchByGenre(genre);
            break;
        case 0:
            break;
        default:
            cout << "Uncorrect choice." << endl;
            break;

        }
    }

    mostPopularMovieInGenre(genre);
    cout << "Information about movies in the store: " << endl;
    displayStore();
}
