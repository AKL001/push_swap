#include "../push_swap.h"


void swap_a(t_stack **a)
{
    int len;

    len = stack_len(*a);
    if (!*a || !a || len == 1)
        return;
    // here we are ponting to the second node 
    *a = (*a)->next;
    // set the first node to prev to point to the second node
    (*a)->prev->prev = (*a);
    // set the first node to pointe to the second node
    if ((*a)->next)
    {
        (*a)->prev->next = (*a)->next;
        // to set the third node prev to point to the first node
        (*a)->next->prev = (*a)->prev;
    }
    // set the second node next to point to the first node
    (*a)->next = (*a)->prev;
    // set the second node prev to NULL
    (*a)->prev = NULL;
    write(1, "sa\n", 3);
}

// void swap_b(t_stack **b)
// {
//     int len;

//     len = stack_len(*b);
//     if (!*b || !b || len == 1)
//         return;
//     // here we bre ponting to the second node 
//     *b = (*b)->next;
//     // set the first node to prev to point to the second node
//     (*b)->prev->prev = (*b);
//     // set the first node to pointe to the second node
//     if ((*b)->next)
//     {
//         (*b)->prev->next = (*b)->next;
//         // to set the third node prev to point to the first node
//         (*b)->next->prev = (*b)->prev;
//     }
//     // set the second node next to point to the first node
//     (*b)->next = (*b)->prev;
//     // set the second node prev to NULL
//     (*b)->prev = NULL;
//     write(1, "sb\n", 3);
// }
void swap_b(t_stack **b)
{
    int len;
    
    // Check pointers first before dereferencing
    if (!b || !*b || !(*b)->next)
        return;
        
    t_stack *first = *b;
    t_stack *second = (*b)->next;
    t_stack *third = second->next;
    
    // Adjust the pointers
    *b = second;        // Make second node the new head
    second->prev = NULL; // New head has no previous
    second->next = first; // Second points to first
    first->prev = second; // First points back to second
    first->next = third;  // First points to third
    
    if (third)
        third->prev = first; // If third exists, point it back to first
        
    write(1, "sb\n", 3);
}

void swap_a_b(t_stack **a,t_stack **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}