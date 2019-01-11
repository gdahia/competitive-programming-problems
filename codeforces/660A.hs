import Data.Char

main = do
	line <- getLine
	let (n:xs) = getInts 1 line
	line <- getLine
	let ps = getInts n line
	let answer = ans ps []
	let k = length answer - n
	putStrLn $ show k
	putStrLn $ foldr1 (\ x st -> st ++ " " ++ x) $ map (show) $ answer

getInts :: Int -> String -> [Int]

getInts 0 _ = []
getInts _ [] = []
getInts x str = map stringToInt $ take x $ words str

stringToInt :: String -> Int

stringToInt str = read str :: Int

ans :: (Integral a) => [a] -> [a] -> [a]

ans [] ret = ret
ans (f:fs) [] = ans fs [f]
ans (f:fs) ret@(s:retms)
	| gcd f s == 1 = ans fs (f:ret)
	| otherwise = ans fs (f:1:ret)
