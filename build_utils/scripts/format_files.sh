for file in `find ../class_descriptions -name \*.txt` ;
do
    cat $file | sed 's/↑/$/' | sed 's/⇒/@/' > ${file%.*}.md;
done
