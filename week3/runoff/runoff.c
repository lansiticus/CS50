#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    //This is the NUMBER of votes
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    //run i for each VOTER
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        // Get rank for EACH CANDIDATE
        for (int j = 0; j < candidate_count; j++)
        {
            //plus one is because people don't rank starting from zero
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            //i is the VOTER NUMBER, j is the RANK NUMBER, name is the NAME OF THE CANDIDATE
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        //look at the TOP CHOICE who is NOT eliminated
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Compare input names against the candidate array and assign the candidate number to the voter/rank array
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return 1;
            break;
        }
    }
    return 0;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
//This is not ranking, but the TOP CHOICE
//check VOTER PREFERENCE IN ORDER and if it matches THE CANDIDATE NUMBER and that candidate's ELIMINATION STATUS is false, add a vote to that candidate's votes
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int ranks = 0; ranks < candidate_count; ranks++)
        {
            int topChoice = preferences[voter][ranks];
            if (candidates[topChoice].eliminated == false)
            {
                candidates[topChoice].votes++;
                break;
            }
        }
    }
    return;
}


// Print the winner of the election, if there is one
bool print_winner(void)
{
//find out if the candidate has a majority of all voters
//the count is based on ALL the voters, even if someone's top choice was eliminated
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int lowCount = voter_count;

    //compare each candidate to find the low vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < lowCount)
        {
            //if the low vote candidate(s) have been eliminated exclude them from determining the low vote count
            if (candidates[i].eliminated == false)
            {
                lowCount = candidates[i].votes;
            }
        }
    }

    return lowCount;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int lowCountCandidates = 0;
    int stillInRace = 0;


    for (int i = 0; i < candidate_count; i++)
    {
        //check to see how many low count candidates are there are
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            lowCountCandidates++;
        }
        //check the TOTAL candidateds still in the race
        if (candidates[i].eliminated == false)
        {
            stillInRace++;
        }
    }
    //a tie is when the low count candidates and the candidates still in the race are the same
    if (lowCountCandidates == stillInRace)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}