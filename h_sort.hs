mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort firstHalf) (mergeSort secondHalf)
  where
    half = length xs `div` 2
    (firstHalf, secondHalf) = splitAt half xs

    merge xs [] = xs
    merge [] ys = ys
    merge (x:xs) (y:ys)
      | x <= y    = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

main :: IO ()
main = do
    putStrLn "Merge Sort test:\n"
    putStr "[9,8,7,6,5,4,3,2,1] = "
    print $ mergeSort [9, 8, 7, 6, 5, 4, 3, 2, 1]
    putStr "[5,-3,2,9,7,-20,10,1,6] = "
    print $ mergeSort [5, -3, 2, 9, 7, -20, 10, 1, 6]
    putStr "\"qwertyuiopasdfghjklzxcvbnm\" = "
    print $ mergeSort "qwertyuiopasdfghjklzxcvbnm"
    putStr "[1] = "
    print $ mergeSort [1]