main = do
	line <- getLine
	let l:r:k:xs = getInts 3 line
	let br = ceiling $ logBase (fromIntegral k) (fromIntegral r)
	putStrLn $ foldr1 (++) $ ans $ map ((' ':) . show) [p | x <- [0,1..br], let p = k^x, p >= l, p <= r]

getInts :: Int -> String -> [Integer]

getInts 0 _ = []
getInts _ [] = []
getInts x str = map stringToInt $ take x $ words str

stringToInt :: String -> Integer

stringToInt str = read str :: Integer

ans [] = ["-1"]
ans x = x
