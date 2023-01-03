#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
// The function takes arguments rank, name, and ranks.
{
    // If name is a match for the name of a valid candidate...
    //MY NOTE: THIS HAS NOTHING TO DO WITH THE RANK ARRAY. IT IS MERELY CHECKED AGAINST THE candidates array.

    //then you should update the ranks array to indicate that the voter has the candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.)
    //MY NOTE: THE RANK ARRAY CORRESPONDS TO THE preferences array, BUT YOU DON'T UPDATE THAT YET.

    //ranks[i] represents the user’s ith preference.

    //The function should return true if the rank was successfully recorded, and false otherwise (if, for instance, name is not the name of one of the candidates). IF NAME NOT FOUND, RETURN FALSE

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
    //The function is called once for each voter, and takes as argument the ranks array, (recall that ranks[i] is the voter’s ith preference, where ranks[0] is the first preference).
{
    // The function should update the global preferences array to add the current voter’s preferences. Recall that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j.
    //MY NOTE: ITERATE OVER preferences ONE ROW AT A TIME AND IF THE NUMBER IN THE RANK IS GREATER THAN THE CORRESPONDING NAME IN THE GRID, THEN INCREMENT 1

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // The function should add all pairs of candidates where one candidate is preferred to the pairs array. A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.
    //MY NOTE: THIS SEEMS RECURSIVE, YOU ONLY NEED TO ITERATE OVER PREFERENCES YOU HAVEN'T SEEN TO GET THE PAIRS.

    // The function should update the global variable pair_count to be the number of pairs of candidates. (The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).
    //MY NOTE: YOU DON'T NEED TO ASSIGN ANYTHING, JUST GET THE NUMBERS.
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // The function should sort the pairs array in decreasing order of strength of victory, where strength of victory is defined to be the number of voters who prefer the preferred candidate. If multiple pairs have the same strength of victory, you may assume that the order does not matter.
    //MY NOTE: THIS ALSO SEEMS RECURSIVE.
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //The function should create the locked graph, adding all edges in decreasing order of victory strength so long as the edge would not create a cycle.
    return;
}

// Print the winner of the election
void print_winner(void)
{
    //The function should print out the name of the candidate who is the source of the graph. You may assume there will not be more than one source.
    //THE SOURCE IS THE ONE THAT HAS ONLY ONE FALSE
    return;
}