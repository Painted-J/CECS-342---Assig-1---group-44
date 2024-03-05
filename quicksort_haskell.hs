module Main where

quickSort :: Ord a => [a] -> [a] -- quick sort a list in Haskell
quickSort [] = []
quickSort (x:xs) = quickSort lo ++ [x] ++ quickSort hi
  where
    lo = filter (<= x) xs
    hi = filter (> x) xs
    
main :: IO ()
main = do
    putStrLn "Quick Sort test:\n"
    putStr "[6,5,4,3,2,1,0] = "
    print $ quickSort [6, 5, 4, 3, 2, 1, 0]
    putStr "['a'] = "
    print $ quickSort ['a']
    putStr "[5, -2, 10, 7, 1, 3, -8] = "
    print $ quickSort [5, -2, 10, 7, 1, 3, -8]
    putStr "[8, 3, 2, 8, 1, 5, 2, 3] = "
    print $ quickSort [8, 3, 2, 8, 1, 5, 2, 3]
    putStr "[] = "
    print $ quickSort ([] :: [Int]) -- Test case with an empty list