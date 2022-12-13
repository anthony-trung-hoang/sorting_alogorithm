#include <bits/stdc++.h>
using namespace std;

// Output function
void printArray(int arr[], int sz)
{
    for (int i = 1; i <= sz; i++)
    {
        printf("Elements no %d : %d \n", i, arr[i]);
    }
}
void writeToFile(ofstream &outputFile, int arr[], int size)
{
    for (int i = 1; i <= size; i++)
        outputFile << arr[i] << endl;
}

// Input options
// 1. Read from keyboard
void readArrayFromKeyBoard(int arr[], int *sz)
{
    int sizeInput;
    printf("Hay nhap so luong phan tu cua day can sap xep: ");
    cin >> sizeInput;
    for (int i = 1; i <= sizeInput; i++)
    {
        printf("Elements no %d: \n", i);
        scanf("%d", &arr[i]);
    }
    *sz = sizeInput;
}

// 2. Generate random array
void generateRandomArray(int arr[], int *sz, int upper_bound, int lower_bound)
{
    int sizeInput;
    printf("Hay nhap so luong phan tu cua day can sap xep: ");
    cin >> sizeInput;

    for (int i = 1; i <= sizeInput; i++)
        arr[i] = rand() % (upper_bound - lower_bound) + lower_bound;
    *sz = sizeInput;
}

// 3. Readfrom a file
void readIntegersFromFile(const char *file_name, int arr[], int *sz)
{
    FILE *file = fopen(file_name, "r");

    int i = 1;
    int num;
    fscanf(file, "%d", &num);
    *sz = num;
    while (fscanf(file, "%d", &num) > 0)
    {
        arr[i] = num;
        i++;
    }
    fclose(file);
}

// Sort algorithm
// 1. Basic sort: selection sort, insertion sort, bubble sort

void selectionSort(int arr[], int num)
{
    for (int k = 1; k < num; k++)
    {
        int min = k;
        for (int j = k + 1; j <= num; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[k];
        arr[k] = tmp;
    }
}

void insertionSort(int arr[], int num)
{
    for (int k = 2; k <= num; k++)
    {
        int last = arr[k];
        int j = k;
        while (j > 1 && arr[j - 1] > last)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = last;
    }
}

void bubbleSort(int arr[], int num)
{
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 1; i < num; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        // printf("\n");
        //  printArray(arr, num);
    } while (swapped == 1);
}

// 2. Advanced Sort

// Merge sort

void Tmerge(int arr[], int L, int M, int R, int n)
{
    int *TA = new int[n + 1];
    int i = L;
    int j = M + 1; // two indices to view 2 subarrays
    for (int k = L; k <= R; k++)
    {
        if (i > M)
        {
            TA[k] = arr[j];
            j++;
        }
        else if (j > R)
        {
            TA[k] = arr[i];
            i++;
        }
        else
        {
            if (arr[i] < arr[j])
            {
                TA[k] = arr[i];
                i++;
            }
            else
            {
                TA[k] = arr[j];
                j++;
            }
        }
    }
    for (int k = L; k <= R; k++)
        arr[k] = TA[k];
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Tạo các mảng tạm */
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int L, int R)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);
        merge(arr, L, M, R);
    }
}

// Quick Sort
int partition(int A[], int L, int R, int indexPivot)
{
    int pivot = A[indexPivot];
    int temp;
    temp = A[indexPivot];
    A[indexPivot] = A[R];
    A[R] = temp; // move pivot to the end of the unsorted array
    int storeIndex = L;
    for (int i = L; i <= R - 1; i++)
    {
        if (A[i] < pivot)
        {
            int temp1;
            temp1 = A[storeIndex];
            A[storeIndex] = A[i];
            A[i] = temp1;
            storeIndex++;
        }
    }
    int temp2;
    temp2 = A[storeIndex];
    A[storeIndex] = A[R];
    A[R] = temp2;
    return storeIndex;
}

void quickSort(int A[], int L, int R)
{
    // base case: there is only one element (or 0)
    if (L < R)
    {
        int indexPivot = (L + R) / 2;
        indexPivot = partition(A, L, R, indexPivot);
        if (L < indexPivot)
            quickSort(A, L, indexPivot - 1);
        if (indexPivot < R)
            quickSort(A, indexPivot + 1, R);
        // printArray(A, R - L + 1);
    }
}

// Heapsort
void Heapify(int A[], int i, int size)
{
    // heapify from A[i]
    int L = 2 * i, R = 2 * i + 1;
    int max = i;
    if (L <= size && A[L] > A[i])
        max = L;
    if (R <= size && A[R] > A[max])
        max = R;
    if (max != i)
    {
        int tempor = A[i];
        A[i] = A[max];
        A[max] = tempor;
        Heapify(A, max, size);
    }
}

void buildHeap(int A[], int size)
{
    for (int i = size / 2; i >= 1; i--)
        Heapify(A, i, size);
}

void heapSort(int A[], int size)
{
    buildHeap(A, size);
    // printf("\nFirst heap:\n");
    //   printArray(A, size);
    printf("\n");
    for (int i = size; i > 1; i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        Heapify(A, 1, i - 1);
        // printf("Step %d\n", size - i + 1);
        // printArray(A, size);
        // printf("\n");
    }
}

int main()
{
    int n;
    system("cls");
    srand((int)time(0));
    int *arr = new int[n + 1];
    int uprBound, lwrBound;
    int choice1 = 0;
    int choice = 0;
    char fileName[20];
    clock_t start, end;
    double cpu_time_used;
    ofstream outputFile;

    int *arrForSort = new int[n + 1];

    do
    {
        system("cls");
        do
        {
            printf("\t\t\t ================CHON DAU VAO================\n");
            printf("\t\t\t |1. Tu nhap tu ban phim                    |\n");
            printf("\t\t\t |2. Sinh ngau nhien                        |\n");
            printf("\t\t\t |3. Doc tu file                            |\n");
            printf("\t\t\t ===================THOAT====================\n");
            printf("\t\t\t |4. Thoat chuong trinh                    |\n");
            printf("Ban chon: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                readArrayFromKeyBoard(arr, &n);
                printArray(arr, n);
                break;
            case 2:
                printf("Nhap can tren va can duoi: ");
                printf("\nCan tren: ");
                scanf("%d", &uprBound);
                printf("Can duoi: ");
                scanf("%d", &lwrBound);
                generateRandomArray(arr, &n, uprBound, lwrBound);
                printArray(arr, n);
                break;
            case 3:
                printf("\nNhap ten file: ");
                fflush(stdin);
                gets(fileName);
                fflush(stdin);
                readIntegersFromFile(fileName, arr, &n);
                printArray(arr, n);
                break;
            case 4:
                exit(1);
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
            }
        } while (!(choice >= 1 and choice <= 4));
        choice = 0;
        do
        {
            printf("\t\t\t =========CHON THUAT TOAN SAP XEP============\n");
            printf("\t\t\t |1. Sap xep chon                           |\n");
            printf("\t\t\t |2. Sap xep chen                           |\n");
            printf("\t\t\t |3. Sap xep noi bot                        |\n");
            printf("\t\t\t |4. Sap xep tron                           |\n");
            printf("\t\t\t |5. Sap xep nhanh                          |\n");
            printf("\t\t\t |6. Sap xep vun dong                       |\n");
            printf("\t\t\t ===================THOAT====================\n");
            printf("\t\t\t |7. Thoat chuong trinh                    |\n");
            printf("Ban chon: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                // selection sort
                start = clock();
                selectionSort(arrForSort, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 2:
                // insertion sort
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                start = clock();
                insertionSort(arrForSort, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 3:
                // bubble sort
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                start = clock();
                bubbleSort(arrForSort, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 4:
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                start = clock();
                mergeSort(arrForSort, 1, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 5:
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                start = clock();
                quickSort(arrForSort, 1, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 6:
                for (int i = 1; i <= n; i++)
                {
                    arrForSort[i] = arr[i];
                }
                start = clock();
                heapSort(arrForSort, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time used in ms: %f\n", 1000000 * cpu_time_used);
                break;

            case 7:
                exit(1);
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
            }
        } while (!(choice >= 1 and choice <= 7));
        choice = 0;
        do
        {
            printf("\t\t\t ================CHON DAU RA=================\n");
            printf("\t\t\t |1. Console                                |\n");
            printf("\t\t\t |2. File                                   |\n");
            printf("\t\t\t ===================THOAT====================\n");
            printf("\t\t\t |3. Thoat chuong trinh                    |\n");
            printf("Ban chon: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printArray(arrForSort, n);
                break;
            case 2:
                outputFile.open("sortedArray.txt");
                writeToFile(outputFile, arrForSort, n);
                break;
            case 3:
                exit(1);
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
            }
        } while (!(choice >= 1 and choice <= 3));
        choice = 0;
        do
        {
            printf("\t\t\t ==========Ban co muon tiep tuc khong?==========\n");
            printf("\t\t\t |1. Co                                        |\n");
            printf("\t\t\t |2. Khong                                     |\n");
            printf("Ban chon: ");
            scanf("%d", &choice1);
            switch (choice1)
            {
            case 1:
                break;
            case 2:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
            }
        } while (!(choice1 == 1 || choice1 == 2));
    } while (choice1 != 2);
    delete[] arrForSort;
    delete[] arr;
    outputFile.close();
    return 0;
}