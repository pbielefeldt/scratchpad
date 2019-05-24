void funny_tclonesarray_stuff(size_t nentries=10)
{
    TClonesArray arr("TH1D");
    
    for (size_t count=0; count<nentries; count++)
    {
        new(arr[count]) TH1D(TString::Format("histo_%zu", count), "hic sunt dracones", 10, 0, 200);
    }
    
    std::cout << "created and filled array" << std::endl;
    std::cout << "entries: " << arr.GetEntries() << " (" << arr. GetEntriesFast() << " fast):" << std::endl;
    
    for (Int_t count=0; count<arr.GetEntriesFast(); count++)
    {
        std::cout << arr.At(count)->GetName() << std::endl;
    }
    
    // just random deletes
    arr.RemoveAt(2);
    arr.RemoveAt(4);
    std::cout << "deleted entrie 2 and 4" << std::endl;
    std::cout << "entries: " << arr.GetEntries() << " (" << arr. GetEntriesFast() << " fast):" << std::endl;
    
    for (Int_t count=0; count<arr.GetEntriesFast(); count++)
    {
        if (arr.At(count)==nullptr) continue;
        else
            std::cout << arr.At(count)->GetName() << std::endl;
    }
    
    arr.Compress();
    std::cout << "compressed" << std::endl;
    std::cout << "entries: " << arr.GetEntries() << " (" << arr. GetEntriesFast() << " fast):" << std::endl;
    for (Int_t count=0; count<arr.GetEntriesFast(); count++)
    {
        std::cout << arr.At(count)->GetName() << std::endl;
    }
    
}

