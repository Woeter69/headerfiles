local sorting = {}

function sorting.BubbleSort(arr, less)
    local n = #arr
    for i = 1, n - 1 do
        for j = 1, n - i do
            if less(arr[j+1], arr[j]) then
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
    end
end

function sorting.SelectionSort(arr, less)
    local n = #arr
    for i = 1, n - 1 do
        local minIndex = i
        for j = i + 1, n do
            if less(arr[j], arr[minIndex]) then
                minIndex = j
            end
        end
        arr[i], arr[minIndex] = arr[minIndex], arr[i]
    end
end

function sorting.InsertionSort(arr, less)
    local n = #arr
    for i = 2, n do
        local key = arr[i]
        local j = i - 1
        while j >= 1 and less(key, arr[j]) do
            arr[j+1] = arr[j]
            j = j - 1
        end
        arr[j+1] = key
    end
end

local function heapify(arr, n, i, less)
    local largest = i
    local left = 2 * i
    local right = 2 * i + 1

    if left <= n and less(arr[largest], arr[left]) then
        largest = left
    end

    if right <= n and less(arr[largest], arr[right]) then
        largest = right
    end

    if largest ~= i then
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest, less)
    end
end

function sorting.HeapSort(arr, less)
    local n = #arr

    for i = math.floor(n / 2), 1, -1 do
        heapify(arr, n, i, less)
    end

    for i = n, 2, -1 do
        arr[1], arr[i] = arr[i], arr[1]
        heapify(arr, i - 1, 1, less)
    end
end

function sorting.QuickSort(arr, less)
    local function partition(low, high)
        local pivot = arr[high]
        local i = low - 1
        for j = low, high - 1 do
            if less(arr[j], pivot) then
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]
            end
        end
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    end

    local function quickSortHelper(low, high)
        if low < high then
            local pi = partition(low, high)
            quickSortHelper(low, pi - 1)
            quickSortHelper(pi + 1, high)
        end
    end

    quickSortHelper(1, #arr)
end

function sorting.MergeSort(arr, less)
    local function merge(low, mid, high)
        local n1 = mid - low + 1
        local n2 = high - mid
        local L = {}
        local R = {}
        for i = 1, n1 do L[i] = arr[low + i - 1] end
        for j = 1, n2 do R[j] = arr[mid + j] end
        
        local i, j, k = 1, 1, low
        while i <= n1 and j <= n2 do
            if not less(R[j], L[i]) then
                arr[k] = L[i]
                i = i + 1
            else
                arr[k] = R[j]
                j = j + 1
            end
            k = k + 1
        end
        while i <= n1 do
            arr[k] = L[i]
            i = i + 1
            k = k + 1
        end
        while j <= n2 do
            arr[k] = R[j]
            j = j + 1
            k = k + 1
        end
    end

    local function mergeSortHelper(low, high)
        if low < high then
            local mid = math.floor((low + high) / 2)
            mergeSortHelper(low, mid)
            mergeSortHelper(mid + 1, high)
            merge(low, mid, high)
        end
    end

    mergeSortHelper(1, #arr)
end

return sorting