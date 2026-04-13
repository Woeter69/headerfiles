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

return sorting