#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Compare input names against the array
        if (strcmp(name, candidates[i].name) == 0)
        {
            //add a vote for a good name
            candidates[i].votes++;
            return 1;
            break;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int HighCount = 0;
    int WinnerNumber = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        //find out what the highest vote count is
        if (candidates[i].votes > HighCount)
        {
            HighCount = candidates[i].votes;
        }
    }

    //Compare the high count to the number of votes each candidate recieved. Print those whose total equal the high count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == HighCount)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
// for (int i = 0; i < candidate_count; i++)
//     {
//         if (candidates[i].votes == HighCount)
//         {
//             WinnerNumber++;
//         }
//     }

// if (WinnerNumber > 1)
//     {
//         printf("It's a tie.\n");
//         return;
//     }

