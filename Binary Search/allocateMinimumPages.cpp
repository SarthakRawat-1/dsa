// Problem Statement :- https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// Consider {12, 34, 67, 90} to be distributed among 2 students.
// Intially start distributing max 1 page to a student. But this is not possible, as 1 < 12. So increase this repeatedly, till you get 12. Here, now allot 12 pages book to first student.
// Now, we can't give second book to first student as 12 + 34 = 46 but we have restricted max pages to 12. So, now as our answer is not possible at 12 pages (because we don't have any other book to give to second student), we will increase max page repeatedly, till we get 34.
// Now, book with 34 pages can't be given to first student as again 12 + 34 = 46 > 34. So we give this book to second student.
// Now, again, as 67 pages book is far greater than max (which is 34), we will increase max pages repeatedly, till we get to 46 pages max. This way, we can give both 12 and 34 pages book to student one now.
// But this is a lot tedious because now we have to increase max till 67 if we want to give third book to student two.
// So, instead of starting from 1 max page, our starting point will be the max no. of pages in the array. This is because this is the least amount of pages a student may get.
// NOTE :- Array may not be in sorted order. Our solution works for both.
// So now, 12 and 34 can be given to student one but not 67 as 12 + 34 + 67 = 113 > 90, so give 67 to student two. But now 90 can not be given to any of the two students. So start increasing max repeatedly.
// Once, you reach 113, you can now give 12 + 34 + 67 to student one and 90 can go to student two.
// But instead of jumping one by one, we can jump a lot. Let's say when we didn't get answer at 90 max, we jump to 150 max. For this also, we will get required answer. In this case, jump to the left, let's say we arrive at 120. here also we can get required answer so jump to left again.
// Hence, if we don't get answer, jump to right, if you get answer (means all book are distributed) jump to left. Don't get answer means we are not able to distribute the books among students. For eg :- Let's say 108, in this case, we can give 12 and 34 to student 1 but not 67. We can give 67 to student 2 but not 90 now, as it'll exceed max. So, 90 remains undistributed.
// In our code, we will find if we were able to distribute books or not, based on count and M variable. Consider previous eg, we can add one more student to give 90 book to that, but now we need 3 students instead of 2. So, in this case, also books can't be distributed among two, hence jump to right.
// Endpoint will be sum of array, this is because in worst case (there can only be 1 page in entire array which we have to give to one student only i.e. all books go to one student). 
// So our starting point will be max of array, and endpoint will be sum of array.
 
#include <bits/stdc++.h>
using namespace std;

int findPages(int A[], int N, int M) {
    // If there are more students than books, allocation is not possible
    if (M > N) {
        return -1;
    }

    // Initialize start and end for binary search
    int start = 0, end = 0;
    int mid, ans; // During each iteration of the binary search, mid represents a candidate for the maximum number of pages that can be allocated to any student. The goal is to minimize this maximum allocation while ensuring that all books can be distributed among the students.

    // Set start to the max number of pages in any single book
    // Set end to the sum of all book pages (worst case: one student gets all books)
    for (int i = 0; i < N; i++) {
        start = max(start, A[i]);  // Find the largest book
        end += A[i];  // Calculate the total number of pages
    }

    // Perform binary search to find the minimum possible maximum pages
    while (start <= end) {
        mid = start + (end - start) / 2;  // Calculate mid

        int pages = 0;  // Current sum of pages allocated to the current student
        int count = 1;  // Number of students needed (start with 1)

        // Try to allocate books such that no student gets more than mid pages
        for (int i = 0; i < N; i++) {
            pages += A[i];  // Add current book to current student's pages

            // If adding this book exceeds the current mid, allocate it to a new student
            if (pages > mid) {
                count++;  // New student needed
                pages = A[i];  // Allocate current book to the new student
            }
        }

        // If it's possible to allocate books with the current number of students (<= M)
        // When the condition count <= M holds true, it means that it is feasible to allocate the books such that no student receives more than mid pages, and we do not exceed the number of available students (M). In this case, mid is a potential valid solution because it shows that you can distribute the books with the current maximum page limit.
        // For count < M also, we are coming to left and storing ans because :- If we can distribute books among < M students, then we can distribute it among M students also. But the opposite is not true. 
        if (count <= M) {
            ans = mid;  // Store the possible answer
            end = mid - 1;  // Try to minimize further by decreasing the maximum pages

            // The storage of ans is performed only when count <= M. This means that under the current mid value, it is possible to allocate the books such that no student receives more than mid pages and that the total number of students required does not exceed M.
            // By ensuring count is within the limit, we are effectively checking that all students can receive at least one book each under the maximum page constraint set by mid.
        } else {
            start = mid + 1;  // Increase the maximum pages allowed
        }
    }

    return ans;  // Return the minimum possible maximum pages
}

int main() {
    int A[] = {10, 20, 30, 40};
    int N = 4;
    int M = 2;
    cout << findPages(A, N, M) << endl;
}

// This same code will also solve the Problem Statements :- https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1 and https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
