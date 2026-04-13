local search = {}

function search.LinearSearch(arr, target)
    for i, val in ipairs(arr) do
        if val == target then
            return i
        end
    end
    return -1
end

function search.BinarySearch(arr, target, less)
    local low = 1
    local high = #arr

    while low <= high do
        local mid = math.floor(low + (high - low) / 2)
        if not less(arr[mid], target) and not less(target, arr[mid]) then
            return mid
        end
        if less(arr[mid], target) then
            low = mid + 1
        else
            high = mid - 1
        end
    end
    return -1
end

return search