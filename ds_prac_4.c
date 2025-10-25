#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
    char name[30];
    struct list *next;
    struct list *prev;
}*CLL;

CLL getnode()
{
    CLL song;
    song = malloc(sizeof(struct list));
    song->next=NULL;
    song->prev=NULL;
return song;
}

CLL head = NULL, temp;

void insertSong(){
    temp = getnode();
            printf("Enter song name: ");
            scanf("%s", temp->name);

            if (head == NULL)
            {
                head = temp;
                head->next = head;
                head->prev = head;
            }
            else
            {
                temp->next = head;
                temp->prev = head->prev;
                head->prev->next = temp;
                head->prev = temp;
            }
}
void displaySong(){
if (head == NULL) {
    printf("No songs to display.\n");
    }
    else{
        printf("Songs in the playlist:\n");
        temp = head;

        do {
            printf("\t%s\n", temp->name);
            temp = temp->next;
        }while (temp != head);
    }
printf("\n");
}
void deleteSong(){
 if (head == NULL) {
                printf("No songs to delete.\n");
            } else {
                char delName[30];
                printf("Enter the name of the song to delete: ");
                scanf("%s", delName);

                temp = head;
                CLL toDelete = NULL;
                do {
                    if (strcmp(temp->name, delName) == 0) {
                        toDelete = temp;
                        break;
                    }
                    temp = temp->next;
                } while (temp != head);

                if (toDelete) {
                    if (toDelete->next == toDelete) {
                        head = NULL;
                    } else {
                        toDelete->prev->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                        if (toDelete == head) {
                            head = toDelete->next;
                        }
                    }
                    free(toDelete);
                    printf("Song deleted successfully.\n");
                } else {
                    printf("Song not found.\n");
                }
            }
}
void searchSong(){
    if (head == NULL) {
        printf("No songs to search.\n");
                }
    else {
        char searchName[30];
        printf("Enter the name of the song to search: ");
        scanf("%s", searchName);

        temp = head;
        int found = 0;
        do {
            if (strcmp(temp->name, searchName) == 0) {
                printf("Song '%s' found in the playlist.\n", searchName);
                found = 1;
                break;
            }
                temp = temp->next;
        } while (temp != head);

            if (!found) {
                printf("Song '%s' not found in the playlist.\n", searchName);
            }
    }
}
/*void playSong(){
    if (head == NULL) {
        printf("No songs to play.\n");
    } else {
        temp = head;
        printf("Playing songs in the playlist:\n");
        do {
            printf("Playing: %s\n", temp->name);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}*/
void countSongs(){
    if (head == NULL) {
        printf("No songs in the playlist.\n");
    } else {
        int count = 0;
        temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        printf("Total number of songs in the playlist: %d\n", count);
    }
    printf("\n");
}
void playSong() {
    if (head == NULL) {
        printf("No songs to play.\n");
        return;
    }

    temp = head;
    char choice;
    printf("Playing songs continuously. Press 'n' for next, 'p' for previous, 'q' to quit.\n");

    do {
        printf("Now Playing: %s\n", temp->name);
        printf("Enter choice (n, p, q): ");
        scanf(" %c", &choice);

        if (choice == 'n')
            temp = temp->next;
        else if (choice == 'p')
            temp = temp->prev;

    } while (choice != 'q');

    printf("Playback stopped.\n\n");
}

int main()
{
    int ch;

while (1)
{

    printf("Enter choice:\n\t1.Add a Song\n\t2.Display the Playlist\n\t3.Delete a Song\n\t4.Searching for a Song\n\t5.Playing a Song\n\t6.Count the Songs\n\t7.Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            insertSong();
            break;
        case 2:
            displaySong();
            break;
        case 3:
            deleteSong();
            break;
        case 4:
            searchSong();
            break;
        case 5:
            playSong();
            break;
        case 6:
            countSongs();
            break;
        case 7:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }
}

}
//m
/*
1. Inserting a Song
2. Deleting a Song
3. Playing Songs (Traversal)
4. Searching for a Song
5. Displaying the Playlist
6. Count the Songs
*/
