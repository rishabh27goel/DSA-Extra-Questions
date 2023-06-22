
// Two Iterations
// Time : O(n + m)  Space : O(1)

// Node* findIntersection(Node *firstHead, Node *secondHead)
// {
//     Node* itr1 = firstHead;
//     Node* itr2 = secondHead;

//     while (itr1 != NULL && itr2 != NULL) {

//       itr1 = itr1->next;
//       itr2 = itr2->next;

//       if(itr1 == itr2)
//         return itr1;

//       if (itr1 == NULL) {
      
//         itr1 = secondHead;
//       }
      
//       if(itr2 == NULL) {
          
//         itr2 = firstHead;
//       }
//     }

//     return NULL;
// }