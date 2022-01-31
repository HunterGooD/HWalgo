package models 

type FileIndexer struct {
    File []WordIdx `json:"file"` // просто корень json
    Path string `json:"path"` // папка к которой принадлежит индексирующий файл
}

type WordIdx struct {
    Value string `json:"value"` // индесное слово
    InFiles []WordFile `json:"in_files"` // файлы в которых встречалось слово
}

type WordFile struct {
    Path string `json:"path"` // путь к файлу в котором нашлось слово
    StartWordIdx []int `json:"start_word_idx"` // индексы начала слова (одно слово в файле может встретится много раз)
}
