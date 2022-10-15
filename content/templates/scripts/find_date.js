function find_date(tp) {
    content = tp.file.content;
    const startPos = content.indexOf('<div align="right">')
    const endPos = content.indexOf('</div>')
    if (startPos == -1 || endPos == -1 || endPos < startPos) {
        return ""
    } else {
        return content.substring(startPos+'<div align="right">'.length,endPos).trim()
    }
}
module.exports = find_date;
