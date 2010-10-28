-----------------------------------------------------------------------------
-- |
-- Module      :  Zipf
-- Copyright   :  © 2006 Bart Massey
-- License     :  MIT
-- 
-- Maintainer  :  bart@cs.pdx.edu
-- Stability   :  experimental
-- Portability :  portable
-----------------------------------------------------------------------------

import System.Environment
import List
import Char
import qualified Data.Map as Map

-- |Simultaneously lowercase chars and turn all non-alpha
-- chars into whitespace.
clean :: Char -> Char
clean c | isAlpha c = toLower c
clean _ = ' '

-- |A frequency table maps words to counts.
type FTable = Map.Map String Integer

-- |Increment the count of word w in the frequency table m.
increment_word :: FTable -> String -> FTable
increment_word m w = Map.insertWith (+) w 1 m

--- The function foldl is a standard Haskell function for
--- iterating over a list.
---
-- |Given a list of words l, increment the count in the
-- frequency table m for each word in l, returning the
-- resulting table.
count_words :: [String] -> FTable
count_words l = foldl increment_word Map.empty l

-- |Given a word and its frequency, produce the output string in
-- its expected format.
format :: (Integer, Integer) -> String
format (i, c) = show (1.0 / fromIntegral i) ++ " " ++ show c

-- |This convenience operator '>.=' is just the reverse composition
-- operator, here to let us write "pipelines" conveniently.
(>.=) :: (a -> b) -> (b -> c) -> (a -> c)
f >.= g = g . f
infixr 9 >.=

--- The Haskell interact function expects as an argument
--- a function from a list of characters to a list of
--- characters; it applies that function to standard input
--- to produce standard output.  Lazy evaluation makes this
--- a reasonable thing to do.
---
-- |Emit Zipf's Law data for a text presented
--  on standard input.
main :: IO ()
main = do
  interact
    (map clean >.= words >.= count_words >.=
    Map.elems >.= sort >.= reverse >.= zip [1..]
     >.= reverse >.= map format >.= unlines)
