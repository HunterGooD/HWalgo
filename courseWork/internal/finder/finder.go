package finder

import (
	"sort"

	"github.com/HunterGooD/HWalgo/courseWork/internal/models"
)

type Finder struct {
    File models.FileIndexer
}

func (f *Finder) search(wordSearch string) {
    index := sort.Search(len(f.File.File), func(i int) bool {
        return f.File.File[i].Value == wordSearch
    })
}
