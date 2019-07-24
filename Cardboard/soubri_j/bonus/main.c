#include "../not_rp1.h"
#include <stdio.h>
#include <time.h>

void print_character_position(character_t *target);
void print_orientation(character_t *target);
int main(void)
{
    srandom(time(NULL));
    character_t *player = new_character(0, E_PLAYER, E_NORTH, ((int[]) { 5, 5}));

    print_character_position(player);
    character_move(player, E_FORWARD);
    print_character_position(player);
    character_move(player, E_LEFT);
    print_character_position(player);
    character_move(player, E_BACKWARD);
    print_character_position(player);
    character_move(player, E_RIGHT);
    print_character_position(player);

    print_orientation(player);
    character_look(player, E_EAST);
    print_orientation(player);
    character_look(player, E_SOUTH);
    print_orientation(player);
    character_look(player, E_WEST);
    print_orientation(player);
    character_look(player, E_NORTH);
    print_orientation(player);


    inventory_t *inv = new_inventory();

    item_t *gun = new_item(1, E_GUN, ((int []) { 0, 0 }));
    item_t *knife = new_item(2, E_KNIFE, ((int []) { 1, 1 }));
    item_t *key = new_item(3, E_KEY, ((int []) { 2, 2 }));
    printf("-----\n");
    add_to_inventory(inv, gun);
    print_inventory(inv);
    printf("-----\n");
    add_to_inventory(inv, knife);
    print_inventory(inv);
    printf("-----\n");
    add_to_inventory(inv, key);
    print_inventory(inv);
    printf("-----\n");
    remove_from_inventory(inv, gun->id);
    print_inventory(inv);
    remove_from_inventory(inv, key->id);
    print_inventory(inv);
    item_t *rm_return = remove_from_inventory(inv, knife->id);
    print_inventory(inv);
    printf("----\n");
    print_item(rm_return);

    printf("----\n");
    printf("----\n");
    add_to_inventory(inv, gun);
    add_to_inventory(inv, knife);
    add_to_inventory(inv, key);
    item_t *find_return = find_in_inventory(inv, knife->id);
    print_item(find_return);
    print_inventory(inv); 

    printf("----\n");
    printf("----\n");
    item_t *find_by_type = find_first_in_inventory(inv, E_GUN);
    print_item(find_by_type); 
    print_inventory(inv); 


    printf("-------- ETNA Tests --------\n");
    item_t *gun1 = new_item(0, E_GUN, ((int []) {0, 0}));
    item_t *gun2 = new_item(1, E_GUN, ((int []) {1, 1}));
    item_t *gun3 = new_item(2, E_GUN, ((int []) {2, 2}));
    item_t *key1 = new_item(3, E_KEY, ((int []) {5, 0}));
    item_t *key2 = new_item(4, E_KEY, ((int []) {1, 4}));
    item_t *knife3 = new_item(5, E_KNIFE, ((int []) {3, 2}));

    inventory_t *inventory = new_inventory();
    if (inventory) {
        my_putstr("--- empty list ---\n");
        print_inventory(inventory);
        add_to_inventory(inventory, gun3);
        add_to_inventory(inventory, knife3);
        add_to_inventory(inventory, key1);
        my_putstr("--- list of size 3 ---\n");
        print_inventory(inventory);
        add_to_inventory(inventory, gun1);
        add_to_inventory(inventory, gun2);
        add_to_inventory(inventory, key2);
        my_putstr("--- list of size 6 ---\n");
        print_inventory(inventory);
        remove_from_inventory(inventory, 5);
        my_putstr("--- remove knife of id 5 ---\n");
        print_inventory(inventory);
        remove_from_inventory(inventory, 5);
        my_putstr("--- remove first gun found ---\n");
        print_inventory(inventory);
        item_t *first_gun = find_first_in_inventory(inventory, E_GUN);
        remove_from_inventory(inventory, first_gun->id);
        my_putstr("--- search knife 5 ---\n");
        print_inventory(inventory);
        item_t *item_5 = find_in_inventory(inventory, 5);
        if (!item_5)
            my_putstr("no item of id 5 found\n");
        my_putstr("--- search first knife ---\n");
        item_t *first_knife = find_first_in_inventory(inventory, E_KNIFE);
        if (!first_knife)
            my_putstr("no knife found\n");
        item_t *item_0 = remove_from_inventory(inventory, 0);
        my_putstr("--- retrieve item 0 after removing it ---\n");
        item_0 = find_in_inventory(inventory, 0);
        if (!item_0)
            my_putstr("no item of id 0 to remove\n");
        clear_inventory(inventory);  
    }
    
    printf("--------------------------------------\n");
    printf("--------- Starting the game ----------\n");
    printf("--------------------------------------\n");
    printf("Generating map...\n");
    character_t *player2 = new_character(0, E_PLAYER, E_NORTH, ((int[]) { 10, 10}));
    map_t *map = generate_random_map(20, 30, 20);
    if (map != NULL)
    {
        printf("Map generated!!!\n");
        printf("Loading map...\n");
        add_character_to_map(map, player2);
        loading_map(map);
        printf("Map loaded!!!\n");
        display_map(map);
        
        for (int i = 0; i < 300; ++i) {
            int rdm = random() % NB_DIRECTIONS;
            character_move(player2, rdm);
            sleep(1);
            loading_map(map);
            checking_interactions(map);
            checking_actions(map);
            display_map(map);
            print_inventory(player2->inventory);
        }
    }

    /*printf("--------------------------------------\n");
    printf("--------- Starting the game ----------\n");
    printf("--------------------------------------\n");
    printf("Generating map...\n");
    character_t *player3 = new_character(10, E_PLAYER, E_NORTH, ((int[]) { 10, 10}));
    character_t *guard = new_character(98, E_GUARD, E_NORTH, ((int []) { 12, 10}));
    map_t *map2 = generate_random_map(20, 0, 0);
    if (map2 != NULL)
    {
        printf("Map generated!!!\n");
        printf("Loading map...\n");
        print_character_position(player3);
        add_item_on_map(map2, E_KNIFE, 99, ((int []) { 11, 10 }));
        add_character_to_map(map2, guard);
        add_character_to_map(map2, player3);
        printf("%d %d\n", map2->nb_characters, map2->items->nb_items);
        loading_map(map2);
        printf("Map loaded!!!\n");
        display_map(map2);
        
        character_move(player3, E_RIGHT);
        loading_map(map2);
        printf("checking interactions \n");
        checking_interactions(map2);
        printf("checking actions \n");
        checking_actions(map2);
        printf("display \n");
        display_map(map2);

        character_move(player3, E_RIGHT);
        loading_map(map2);
        printf("checking interactions \n");
        checking_interactions(map2);
        printf("checking actions \n");
        checking_actions(map2);
        printf("display \n");
        display_map(map2);
    }*/
}

void print_character_position(character_t *target)
{
    printf("[%d] x:%d y:%d\n", target->id, target->coord[E_X], target->coord[E_Y]);
}

void print_orientation(character_t *target)
{
    printf("[%d] azimut:%d\n", target->id, target->azimut);
}