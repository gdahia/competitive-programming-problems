main = do
	line <- getLine
	let x = stringToInt line
	putStrLn $ ans x

ans :: Int -> String

ans 2 = "NO"
ans x = convertToDec $ even x

stringToInt :: String -> Int

stringToInt [] = 0
stringToInt str = read (head $ words str) :: Int

convertToDec :: Bool -> String

convertToDec True = "YES"
convertToDec _ = "NO"
