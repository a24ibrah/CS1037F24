

/**
 * RECORD structure
 * name  - char array for person's name
 * score - float score of record
 */
typedef struct {
  char name[40];
  float score;
} RECORD;

/**
 * NODE structure
 * data  - RECORD data
 * next  - pointer pointing to the next node of singly linked list
 */
typedef struct node {
  RECORD data;
  struct node *next;
} NODE;

/**
 * Singly linked list structure
 * int length  - the number of nodes of the linked list
 * NODE *start - pointer pointing to the first node of the linked list
 */
typedef struct sllist {
  int length;
  NODE *start;
} SLL;


/**
 * Search singly linked list by name key.
 * @param Record *head provides the address of a RECORD structure.
 * @param id Key to search
 * @return Pointer to found node if found; otherwise NULL
 */
Record* sll_search(Record *head, char id[]);

/**
 * Insert new record to linked list at the position sorted by record name field.
 * @param @param Record *head provides the address of a RECORD structure.
 * @param id The id of new record.
 * @param mark The mark data of new record
 */
void sll_insert(Record **head, char id[], float mark);

/**
 * Delete a node of record matched by the name key from linked list.
 * @param @param Record *head provides the address of a RECORD structure.
 * @param id  The id used to find the node for deletion. 
 * @return 1 if deleted a matched node, 0 otherwise. 
 */
void sll_delete(Record **head, char id[]);

// Function to import data from a file into the linked list
void import_data(const char *filename, Record **head);

// Function to process data (count, mean, standard deviation, and median)
void process_data(Record *head);

/**
 * Clean singly linked list, delete all nodes. 
 * @param @param Record *head provides the address of a RECORD structure.
 */
void sll_cleanup(Record **head);

